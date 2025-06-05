// Done ASCII ART
#include <stdio.h>

// Required for Sleep()/sleep() function
#ifdef _WIN32 // Only include if
#include <windows.h>
#else // else
#include <unistd.h>
#endif

void showProgress(int percent)
{
    int bars = percent / 5; // (20) character bar & store in bars
    printf("\r\033[1;33mDownload Progress:\033[0m");
    printf(" [");

    for (int i = 0; i < 20; i++)
    {
        if (i < bars) // Print a progress bar based on no. of bars
        {
            printf("\033[32m█\033[0m"); // Filled bar character
        }
        else
        {
            printf(" "); // Empty spaces: Printed to fill (20 characters - bars) remaining space
        }
    }

    printf("] -%d%%", percent);
    fflush(stdout); // Force immediate display
}

int main()
{

    // 1. Basic progress bar
    printf("\n\033[1mASCII Progress Bar: (1)\033[0m\n");
    printf("==========================================\n\n");

    printf("Basic progress bar:\n");
    for (int i = 0; i <= 100; i += 5)
    {
        showProgress(i); // Function call
        usleep(200000);  // 0.2 seconds delay
    }

    printf("\n\n");
    usleep(500000); // .5 sec delay
    printf("\r\033[1mDownload Completed!\033[0m");

    printf("\n\n");
}