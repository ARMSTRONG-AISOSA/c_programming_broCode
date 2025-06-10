#include <stdio.h>
#include <string.h>

// Platform-specific includes and definitions
#ifdef _WIN32
#include <conio.h> // For getch() on windows
#define ENTER 13
#define BCKSPC 8
#define TAB 9
#else
#include <termios.h> // For terminal control on Unix/Linux
#include <unistd.h>  // For read()
#define ENTER 10     // Line feed on Unix
#define BCKSPC 127   // DEL key on Unix
#define TAB 9

// ANSI Code
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m" // bright magenta text
#define ANSI_COLOR_GREEN "\x1b[32m"          // green text
#define ANSI_COLOR_YELLOW "\x1b[33m"         // yellow text
#define ANSI_COLOR_BLACK "\x1b[30m"          // black text
#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"    // blue text
#define ANSI_BG_WHITE "\x1b[47m"             // wHITE-BG
#define ANSI_BOLD "\x1b[1m"                  // bold
#define ANSI_RESET "\x1b[0m"                 // Reset to default

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

    return ch; // return value at the end of the program
}
#endif

void take_password(char pwd[50])
{
    int i = 0; // Initialize counter
    char ch;   // Intialize letter holder returned from getch()

    printf("Enter password: ");
    fflush(stdout); // Ensure prompt appears immediately

    while (1) // Runs infinitely till this a break statement is met
    {
        ch = getch(); // accept each entered letter one at a time

        if (ch == ENTER || ch == TAB) // Execute here if TAB or ENTER key is entered
        {
            pwd[i] = '\0'; // Null-terminate the string
            break;
        }
        else if (ch == BCKSPC) // remove a letter for every backspace entered
        {
            if (i > 0)
            {
                i--;             // counter
                printf("\b \b"); // Move back, print space, move back again
                fflush(stdout);  // force output
            }
        }
        else if (i < 49) // Prevent buffer overflow -- input from exceeding maximum length pwd[49] (zero indexed) (save space for null terminator == \0)
        {
            pwd[i++] = ch; // Stores the typed character (ch) at index i in the pwd array.
            // Then, it increments i (post-increment), so the next character goes into the next position.
            printf(ANSI_COLOR_BRIGHT_MAGENTA "*" ANSI_RESET); // Visually replace it with an asterisk *,
            fflush(stdout);                                   // Ensures the asterisk * gets immediately printed to the console.
        }
    }
    printf("\n"); // New line after password input
}

//
int check_password_strength(const char *password) // password: Cheack @ notes.txt - 7
{
    if (password == NULL)
    {
        return 0;
    }

    int stringLength = strlen(password);
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < stringLength; i++) // runs through the length of the password(letter after letter) what condition might be through
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            has_upper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            has_lower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            has_digit = 1;
        }
        else
        {
            has_special = 1;
        }
    }

    int score = 0;
    if (stringLength >= 8)
    {
        score++;
    }
    if (stringLength >= 12)
    {
        score++;
    }
    if (has_upper) // if true
    {
        score++;
    }
    if (has_lower)
    {
        score++;
    }
    if (has_digit)
    {
        score++;
    }
    if (has_special)
    {
        score++;
    }

    return score; // return value
}

// Simple hash function (for demonstration - use proper hashing in production)
unsigned int simple_hash(const char *password) //*password: Cheack @ notes.txt - 7
{
    unsigned int hash = 5381;
    int c; // Declares an integer c to store each character of the string, one at a time, as it loops through the string.

    while ((c = *password++)) //loop
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main()
{
    char password[50]; // defined here so this function could still have access to it
    int strength = 0;

    printf("=== Cross-Platform Password Input Demo ===\n\n");

    do
    {
        // Get password from user
        take_password(password);

        // Display Password
        printf("Entered Password: " ANSI_BG_WHITE ANSI_COLOR_BLACK ANSI_BOLD "%s" ANSI_RESET, password);
        printf("\n");

        // Check Password Strength
        strength = check_password_strength(password);
        printf("\nPassword strength score: %d/6\n", strength);

        if (strength < 4) // 0 -3
        {
            printf(ANSI_BOLD "⚠️  Warning: " ANSI_COLOR_YELLOW "Weak" ANSI_RESET ANSI_BOLD " password detected!\n" ANSI_RESET);
            printf("Recommendations:\n");
            printf("- Use at least 8 characters (12+ recommended)\n");
            printf("- Include uppercase and lowercase letters\n");
            printf("- Include numbers and special characters\n\n");

            usleep(100000); // 0.1 sec

            printf("Enter a " ANSI_BOLD "STRONGER" ANSI_RESET " password !!! \n\n");
        }
        else
        {
            printf("\n✅ Password strength is " ANSI_COLOR_GREEN ANSI_BOLD "acceptable\n\n" ANSI_RESET);
        }
    } while (strength < 4);

    // Generate hash (for storage - never store plain text)
    unsigned int hash = simple_hash(password);
    printf("Password hash: " ANSI_COLOR_BRIGHT_BLUE ANSI_BOLD "%u" ANSI_RESET " (for secure storage)\n", hash);
    // printf("Password length: %ld character\n", strlen(password));
    // OR
    printf("Password length: %d character\n", (int)strlen(password));

    return 0;
}