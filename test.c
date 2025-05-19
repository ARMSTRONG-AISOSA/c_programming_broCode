#include <stdio.h>
#include <stdlib.h> // Added for system("cls") or system("clear")
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main()
{
// Clear the screen
#ifdef _WIN32
    system("cls"); // Clear screen on Windows
#else
    system("clear"); // Clear screen on Unix-like systems
#endif

    printf("\n\033[1;36m🎮 QUIZ GAME STARTS NOW 🎮\033[0m\n");
    printf("\033[34mGet ready...\033[0m\n");

    for (int i = 5; i > 0; i--)
    {
        printf("\r\033[33mStarting in %d...\033[0m", i);
        fflush(stdout); //ensures output prints immediately.

#ifdef _WIN32
        Sleep(1000); // milliseconds
#else
        sleep(1); // seconds
#endif
    }

    printf("\nRocket Launched 🚀\n"); // Added a newline before "Rocket Launched"

    return 0;
}
