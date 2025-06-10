#include <stdio.h>
#include <string.h>

// Platform-specific includes and definitions
#ifdef _WIN32
#include <conio.h> // For getch() on Windows
#define ENTER 13
#define BCKSPC 8
#define TAB 9
#else
#include <termios.h> // For terminal control on Unix/Linux
#include <unistd.h>  // For read()
#define ENTER 10     // Line feed on Unix
#define BCKSPC 127   // DEL key on Unix
#define TAB 9

// Custom getch() function for Unix/Linux systems
int getch()
{
    struct termios old_termios, new_termios;
    int ch;

    // Get current terminal settings
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;

    // Disable canonical mode and echo
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    // Read single character
    ch = getchar();

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);

    return ch;
}
#endif

// Simple password strength checker
int check_password_strength(const char *password)
{
    if (password == NULL)
        return 0;

    int len = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    for (int i = 0; i < len; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            has_upper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            has_lower = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            has_digit = 1;
        else
            has_special = 1;
    }

    int score = 0;
    if (len >= 8)
        score++;
    if (len >= 12)
        score++;
    if (has_upper)
        score++;
    if (has_lower)
        score++;
    if (has_digit)
        score++;
    if (has_special)
        score++;

    return score;
}

// Simple hash function (for demonstration - use proper hashing in production)
unsigned int simple_hash(const char *password)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *password++))
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

void takepassword(char pwd[50])
{
    int i = 0; // Initialize counter
    char ch;

    printf("Enter password: ");
    fflush(stdout); // Ensure prompt appears immediately

    while (1)
    {
        ch = getch(); // accept each entered letter one at a time

        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0'; // Null-terminate the string
            break;
        }
        else if (ch == BCKSPC) // remove a letter for every backspace entered
        {
            if (i > 0)
            {
                i--;
                printf("\b \b"); // Move back, print space, move back again
                fflush(stdout);
            }
        }
        else if (i < 49) // Prevent buffer overflow -- input from exceeding maximum length pwd[49] (zero indexed) (save space for null terminator == \0)
        {
            pwd[i++] = ch; // Stores the typed character (ch) at index i in the pwd array.
            // Then, it increments i (post-increment), so the next character goes into the next position.
            printf("*");    // Visually replace it with an asterisk *,
            fflush(stdout); // Ensures the asterisk * gets immediately printed to the console.
        }
    }
    printf("\n"); // New line after password input
}

int main()
{
    char password[50];

    printf("=== Cross-Platform Password Input Demo ===\n\n");

    // Get password from user
    takepassword(password);

    // Display the password (in real applications, avoid this!)
    // Check password strength
    int strength = check_password_strength(password);
    printf("\nPassword strength score: %d/6\n", strength);

    if (strength < 4)
    {
        printf("⚠️  Warning: Weak password detected!\n");
        printf("Recommendations:\n");
        printf("- Use at least 8 characters (12+ recommended)\n");
        printf("- Include uppercase and lowercase letters\n");
        printf("- Include numbers and special characters\n");
    }
    else
    {
        printf("✅ Password strength is acceptable\n");
    }

    // Generate hash (for storage - never store plain text!)
    unsigned int hash = simple_hash(password);
    printf("Password hash: %u (for secure storage)\n", hash);
    printf("Password length: %d characters\n", (int)strlen(password));

    return 0;
}