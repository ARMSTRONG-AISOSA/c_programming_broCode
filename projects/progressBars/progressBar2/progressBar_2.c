// Done ASCII ART
#include <stdio.h>

// Required for Sleep()/sleep() function
#ifdef _WIN32 // Only include if
#include <windows.h>
#else // else
#include <unistd.h>
#endif

void showProgressWithDots(int percent)
{
    int bars = percent / 5; // (20) character bar & store in bars
    printf("\r\033[1;33mUpload Progress:\033[0m");
    printf(" [");

    for (int i = 0; i < 20; i++)
    {
        if (i < bars) // Print a progress (filed dot) based on no. of bars
        {
            printf("\033[35m●\033[0m"); // Filled bar character
        } else {
            printf("\033[35m○\033[0m"); // Empty dot: Printed to fill (20 characters - bars) remaining space
        }
    }

    printf("] -%d%%", percent);
    fflush(stdout); // Force immediate display
}

int main()
{

    // 1. Dot-style progress bar
    printf("\n\033[1mASCII Progress Bar: (2)\033[0m\n");
    printf("==========================================\n\n");

    printf("Dot-style progress bar:\n");
    for (int i = 0; i <= 100; i += 2.5)
    {
        showProgressWithDots(i); // Function call
        usleep(100000);  // 0.1 seconds delay
    }

    printf("\n\n");
    usleep(500000); // .5 sec delay
    printf("\r\033[1mUpload Completed!\033[0m");

    printf("\n\n");

    return 0;
}