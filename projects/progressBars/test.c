#include <stdio.h>
#include <unistd.h>


void showProgressWithShading(int percent)
{
    int bars = percent / 4; // 25 character bar for more granular shading
    printf("\rProcessing: [");

    for (int i = 0; i < 25; i++)
    {
        if (i < bars)
        {
            printf("█"); // Full block
        }
        else if (i == bars)
        {
            // Partial block based on remainder
            int remainder = percent % 4;
            if (remainder == 1)
                printf("▏");
            else if (remainder == 2)
                printf("▎");
            else if (remainder == 3)
                printf("▍");
            else
                printf(" ");
        }
        else
        {
            printf(" ");
        }
    }
    printf("] %3d%%", percent);
    fflush(stdout);
}

int main()
{
    printf("ASCII Progress Bar Examples\n");
    printf("===========================\n\n");



    // Example 4: Shaded progress bar (more granular)
    printf("4. Shaded Progress Bar:\n");
    for (int i = 0; i <= 100; i += 3)
    {
        showProgressWithShading(i);
        usleep(50000); // 0.05 seconds delay
    }
    printf("\n\n");

    // Example 5: Multi-task progress simulation
    printf("5. Multi-task Simulation:\n");

    char tasks[][20] = {
        "Initializing",
        "Loading data",
        "Processing",
        "Saving results",
        "Cleanup"};

    for (int task = 0; task < 5; task++)
    {
        printf("%s:\n", tasks[task]);
        for (int i = 0; i <= 100; i += 5)
        {
            printf("\r%s: [", tasks[task]);
            int bars = i / 5;
            for (int j = 0; j < 20; j++)
            {
                if (j < bars)
                    printf("█");
                else
                    printf("░");
            }
            printf("] %3d%%", i);
            fflush(stdout);
            usleep(30000); // 0.03 seconds
        }
        printf(" ✓\n");
    }

    printf("\nAll tasks completed!\n");

    return 0;
}