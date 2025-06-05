#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("===========================\n\n");

    int counter;

    // Example 5: Multi-task progress simulation
    printf("5. Multi-task Simulation:\n\n");

    char tasks[][20] = {
        "Initializing",
        "Loading data",
        "Processing",
        "Saving results",
        "Cleanup"};

    for (int task = 0; task < 5; task++)
    {
        counter++;
        printf("\033[1mStage %d.\033[0m\n", counter); // add "\n" to flush immediately

        for (int i = 0; i <= 100; i += 2.5)
        {
            printf("\r%s:   [", tasks[task]);
            int bars = i / 2.5; // 40 bars
            for (int j = 0; j < 40; j++)
            {
                if (j < bars)
                    printf("\033[35m█\033[0m");
                else
                    printf("\033[35m░\033[0m");
            }
            printf("] %d%%", i);
            fflush(stdout);
            usleep(40000); // 0.04 seconds
        }
        printf(" ✓\n\n");
    }

    printf("\nAll processes completed!\n");

    return 0;
}