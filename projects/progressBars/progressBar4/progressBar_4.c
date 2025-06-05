// Done ASCII ART
#include <stdio.h>

// Required for Sleep()/sleep() function
#ifdef _WIN32 // Only include if
#include <windows.h>
#else // else
#include <unistd.h>
#endif

void showProgressWithShading(int percent)
{
    int bars = percent / 4; // (25) character bar & store in bars
    printf("\r\033[1;33mRendering:\033[0m");
    printf(" [");

    for (int i = 0; i < 25; i++)
    {
        if (i < bars) // Print a progress bar based on no. of bars
        {
            printf("\033[36m█\033[0m"); // Full block
        }
        else if (i == bars)
        {
            printf("\33[44m|||\033[0m"); // Arrow head for current position

            // // Partial block based on remainder
            // int remainder = percent % 4;
            // if (remainder == 1)
            //     printf("▏");
            // else if (remainder == 2)
            //     printf("▎");
            // else if (remainder == 3)
            //     printf("▍");
            // else
            //     printf(" ");
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
    printf("\n\033[1mASCII Progress Bar: (4)\033[0m\n");
    printf("==========================================\n\n");

    printf("Shaded Progress Bar: \n");
    for (int i = 0; i <= 100; i += 2) // increament of 2
    {
        showProgressWithShading(i); // Function call
        usleep(90000);             // 0.09 seconds delay
    }

    printf("\n\n");
    usleep(500000); // .5 sec delay
    printf("\r\033[1mRendering Completed!\033[0m");

    printf("\n\n");

    return 0;
}