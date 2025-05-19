#include <stdio.h>
#include <stdlib.h> // Added for system("cls") or system("clear")
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Sleep function
void sleep_function(int time)
{
#ifdef _WIN32
    Sleep(time * 1000); // milliseconds
#else
    sleep(time); // seconds
#endif
}

int main()
{
// Clear the screen (terminal)
#ifdef _win32
    system("cls"); // Windows
#else
    system("clear"); // Unix-like
#endif

    printf("\n\033[1;36m🚀 ROCKET TRAVEL STARTS NOW 🎮\033[0m\n");
    printf("\033[34mGet Ready...\033[0m\n");

    for (int sec = 10; sec >= 0; sec--)
    {
        printf("\r\033[33mlift off in %d...\033[0m", sec);
        fflush(stdout); // ensures output prints immediately.

        sleep_function(1);
    }

    printf("\n\nRocket Ascent 🚀\n");
    sleep_function(1);

    printf("\nRocket Gravity Turn 🚀\n");
    sleep_function(2);

    printf("\nRocket Stage Separation 🚀\n");
    sleep_function(2);

    printf("\nOrbit Insertion 🚀\n");
    sleep_function(1);

    printf("\nTravel successful 🚀\n");

    return 0;
}