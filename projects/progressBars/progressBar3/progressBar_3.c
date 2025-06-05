// Done ASCII ART
#include <stdio.h>

// Required for Sleep()/sleep() function
#ifdef _WIN32 // Only include if
#include <windows.h>
#else // else
#include <unistd.h>
#endif

void showProgressWithEquals(int percent)
{
    int bars = percent / 4; // (25) character bar & store in bars
    printf("\r\033[1;33mTransmitting:\033[0m");
    printf(" [");

    for (int i = 0; i < 25; i++)
    {
        if (i < bars) // Print a progress bar based on no. of bars
        {
            printf("\33[44m=\033[0m"); // Equals sign
        } else if (i == bars && percent < 100) {
            printf("\33[44m>\033[0m");// Arrow head for current position
        }
        else
        {
            printf("-"); // Empty spaces: Printed to fill (20 characters - bars) remaining space
        }
    }

    printf("] -%d%%", percent);
    fflush(stdout); // Force immediate display
}

int main()
{

    // 1. Basic progress bar
    printf("\n\033[1mASCII Progress Bar: (3)\033[0m\n");
    printf("==========================================\n\n");

    printf("Equals-style Progress Bar:\n");
    for (int i = 0; i <= 100; i += 1) // increament of 1
    {
        showProgressWithEquals(i); // Function call
        usleep(50000);  // 0.05 seconds delay
    }

    printf("\n\n");
    usleep(500000); // .5 sec delay
    printf("\r\033[1mTransmission Completed!\033[0m");

    printf("\n\n");

    return 0;
}