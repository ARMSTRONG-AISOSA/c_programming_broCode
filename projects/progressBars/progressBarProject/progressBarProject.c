#include <stdio.h>
#include <unistd.h>

void showProgress(int percent)
{
    int bars = percent / 5; // 20 character bar (100% / 5 = 20 bars)
    printf("\rProgress: [");

    for (int i = 0; i < 20; i++)
    {
        if (i < bars)
        {
            printf("█"); // Filled bar character
        }
        else
        {
            printf(" "); // Empty space
        }
    }
    printf("] %3d%%", percent);
    fflush(stdout); // Force immediate display
}

void showProgressWithDots(int percent)
{
    int bars = percent / 5; // 20 character bar
    printf("\rLoading: [");

    for (int i = 0; i < 20; i++)
    {
        if (i < bars)
        {
            printf("●"); // Filled dot
        }
        else
        {
            printf("○"); // Empty dot
        }
    }
    printf("] %3d%%", percent);
    fflush(stdout);
}

void showProgressWithEquals(int percent)
{
    int bars = percent / 5; // 20 character bar
    printf("\rDownload: [");

    for (int i = 0; i < 20; i++)
    {
        if (i < bars)
        {
            printf("="); // Equals sign
        }
        else if (i == bars && percent < 100)
        {
            printf(">"); // Arrow head for current position
        }
        else
        {
            printf("-"); // Dash for empty
        }
    }
    printf("] %3d%%", percent);
    fflush(stdout);
}

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

    // Example 1: Basic progress bar
    printf("1. Basic Progress Bar:\n");
    for (int i = 0; i <= 100; i += 10)
    {
        showProgress(i);
        usleep(200000); // 0.2 seconds delay
    }
    printf("\n\n");

    // Example 2: Dot-style progress bar
    printf("2. Dot-style Progress Bar:\n");
    // for (int i = 0; i <= 100; i += 5)
    for (int i = 0; i <= 100; i += 15)
    {
        showProgressWithDots(i);
        usleep(150000); // 0.15 seconds delay
    }
    printf("\n\n");

    // Example 3: Equals-style progress bar
    printf("3. Equals-style Progress Bar:\n");
    for (int i = 0; i <= 100; i += 8)
    {
        showProgressWithEquals(i);
        usleep(100000); // 0.1 seconds delay
    }
    printf("\n\n");

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