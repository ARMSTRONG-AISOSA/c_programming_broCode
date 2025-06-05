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
    // 5: Multi-task progress simulation
    printf("\n\033[1mASCII Progress Bar: (5)\033[0m\n");
    printf("==========================================\n\n");

    // Variables
    int counter = 0;
    char tasks[5][20] = {
        "Initializing",
        "Loading data",
        "Processing",
        "Saving results",
        "Cleanup"};

    printf("Multi-task Simulation:\n\n");

    for (int task = 0; task < 5; task++) // Execute Each task (0-4) progress Bar
    {
        counter++;
        printf("\033[1mStage %d.\033[0m\n", counter); // add "\n" to flush immediately

        // Execute each progress bar
        for (float i = 0; i <= 100; i += 2.5)
        {
            printf("\r%s: [", tasks[task]);
            int bars = i / 2.5;          // 40 bars
            for (int j = 0; j < 40; j++) // Run 40 times to match the number of bars(filled/empty)
            {
                if (j < bars) // Print filled bars based on available bars
                {
                    printf("\033[35m█\033[0m");
                }
                else
                {
                    printf("\033[35m░\033[0m");
                }
            }
            printf("] - %.2f%%", i);
            fflush(stdout); // force display
            usleep(40000);  // 0.04 seconds
        }
        printf(" ✓\n\n");
    }

    printf("\n\n");
    usleep(500000); // .5 sec delay
    printf("\r\033[1mAll processes completed!\033[0m");

    printf("\n\n");

    return 0;
}