#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Platform-specific includes and definations
#ifdef _WIN32
#include <conio.h>          // For getch() on windows
#include <windows.h>        // beep
#define CLEAR_COMMAND "cls" // Clear command
#define ENTER 13
#define BCKSPC 8
#define TAB 9

#else
#include <termios.h>          // For terminal control on Unix/Linux
#include <unistd.h>           // For read()
#define CLEAR_COMMAND "clear" // Clear command
#define ENTER 10              // Line feed on Unix
#define BCKSPC 127            // DEL key on Unix
#define TAB 9

// Cross-platform getch function
char getch()
{
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt); // get old terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);        // disable buffering and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // set new attributes
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restore old settings
    return ch;
}

#endif

// ANSI Code
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m" // bright magenta text
#define ANSI_COLOR_RED "\x1b[31m"            // red text
#define ANSI_COLOR_GREEN "\x1b[32m"          // green text
#define ANSI_COLOR_YELLOW "\x1b[33m"         // yellow text
#define ANSI_COLOR_BLACK "\x1b[30m"          // black text
#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"    // blue text
#define ANSI_BG_WHITE "\x1b[47m"             // wHITE-BG
#define ANSI_BOLD "\x1b[1m"                  // bold
#define ANSI_RESET "\x1b[0m"                 // Reset to default

struct user
{
    char fullname[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};

void takeinput(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strcspn(ch, "\n")] = 0; // remove trailing newline
}

void takepassword(char pwd[50])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == '\n')
        {
            pwd[i] = '\0';
            printf("\n");
            break;
        }
        else if (ch == BCKSPC || ch == 127)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("*");
        }
    }
}

void beep()
{
#ifdef _WIN32
    Beep(750, 300);
#else
    printf("\a");
#endif
}

int main()
{
#ifdef _WIN32
    system("clor 0b");
#endif

    FILE *fp; // file pointer
    int option;
    int userFound = 0;
    int state = 0;
    struct user user;
    char password2[50];

    printf("\n----------Welcome to authentication system----------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");

    printf("\n\nYour choice:\t");
    scanf("%d", &option);
    getch(); // Clear the new line

    switch (option)
    {
    case 1:
    {
        system(CLEAR_COMMAND);
        printf("\nEnter your full name:\t");
        takeinput(user.fullname);
        printf("Enter your email:\t");
        takeinput(user.email);
        printf("Enter your username:\t");
        takeinput(user.username);
        printf("Enter your contact no:\t");
        takeinput(user.phone);
        printf("Enter your password:\t");
        takepassword(user.password);
        printf("Confirm your password:\t");
        takepassword(password2);

        do
        {
            if (!strcmp(user.password, password2)) // returns 0 if it matches which is seen as false in C. Thus here strcmp is flipped to true
            {
                state = 1;                     // Update state
                fp = fopen("Users.dat", "a+"); // Create, Write to & append new
                if (fwrite(&user, sizeof(struct user), 1, fp))
                {
                    printf("\n\n" ANSI_BOLD ANSI_COLOR_GREEN "User registration successful! " ANSI_RESET "Your username is: %s\n\n", user.username);
                }
                else
                {
                    printf("\n\n" ANSI_BOLD ANSI_COLOR_YELLOW "Sorry! Something went wrong" ANSI_RESET "\n");
                }
                fclose(fp);
            }
            else
            {
                printf("\n\n" ANSI_BOLD ANSI_COLOR_YELLOW "Passwords do not match." ANSI_RESET "\n");
                beep();
                printf("Enter your password:\t");
                takepassword(user.password);
                printf("Confirm your password:\t");
                takepassword(password2);
            }
        } while (state != 1);

        break; // stop here and exit switch statement
    }

    case 2:
    {
        char loggedUsername[50]; // Variable to input for Username
        char loggedPassword[50]; // Variable to input for password
        struct user storedUser;  // defined data structure

        printf("\nEnter your username:\t");
        takeinput(loggedUsername); // input for Username
        printf("\nEnter your password:\t");
        takepassword(loggedPassword); // input for password

        fp = fopen("Users.dat", "r"); // reads the opened file
        if (!fp)                      // "non Zero"; success ruturns 0(false), so !0 is true; any other thing would be read as false.
        {
            printf("\nCould not open user database.\n");
            return 1;
        }

        while (fread(&storedUser, sizeof(struct user), 1, fp)) // loop check @ notes.txt
        {
            if (!strcmp(storedUser.username, loggedUsername)) // returns 0 if equal; Check if the current loop user data matches the logged in username
            {
                if (!strcmp(storedUser.password, loggedPassword))
                {
                    printf("Worked2");
                    system(CLEAR_COMMAND);
                    printf("\n\t\t\t\t\tWelcome %s", storedUser.fullname);
                    printf("\n\n| Full Name:\t%s", storedUser.fullname);
                    printf("\n| Email:\t%s", storedUser.email);
                    printf("\n| Username:\t%s", storedUser.username);
                    printf("\n| Contact no.:\t%s\n", storedUser.phone);
                }
                else
                {
                    printf("\n\n" ANSI_BOLD ANSI_COLOR_YELLOW "Invalid Password!" ANSI_RESET "\n"); // password doesn't Match

                    beep();
                }
                userFound = 1; // change to 1 if a user data/account is found
                break;
            }
        }

        fclose(fp); // close stream

        if (!userFound) // In C, a value of 0 is treated as false, and any non-zero value is treated as true. Thus here userFound is flipped to true
        {
            printf("\n\n" ANSI_COLOR_YELLOW ANSI_BOLD "User is not registered!" ANSI_BOLD "\n");
            beep();
        }
        break;
    }

    case 3:
    {
        printf("\n" ANSI_BOLD "----------Bye Bye----------" ANSI_RESET "\n");
        return 0;
        break;
    }

    default:
    {
        printf("\n" ANSI_BOLD ANSI_COLOR_RED "Wrong Option; Start Over!!!" ANSI_RESET "\n\n");
        break;
    }
    }

    return 0;
}
