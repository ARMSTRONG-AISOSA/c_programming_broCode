#include <stdio.h>
#include <time.h>

int main()
{
    // check @ txt --> 1.0 & 1.2 
    clock_t start_clock, end_clock; // typedef long clock_t
    double elapsed_time;

    start_clock = clock(); // Get (CPU) start clock time
    printf("Program start time: %ld\n", start_clock);

    // Simulate some work
    for (int i = 0; i < 100000000; i++)
        ;
    for (int i = 0; i < 200000000; i++)
        ;

    end_clock = clock(); // Get (CPU) end clock time
    printf("Proram end time: %ld\n", end_clock);

    

    // check @ txt --> i-1.2.1 for further breakdown
    elapsed_time = (double)(end_clock - start_clock) /
                   CLOCKS_PER_SEC;

    printf("CPU (processor) time used by program: %.2f seconds.\n", elapsed_time);

    return 0;
}