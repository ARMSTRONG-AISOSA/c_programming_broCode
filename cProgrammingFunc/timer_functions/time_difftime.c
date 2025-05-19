#include <stdio.h>
#include <time.h>

int main() {
    // check @ txt --> 1.0 & 1.1
    // ps: typedef long (int) time_t --> %ld 
    time_t start_time, end_time;
    double elapsed_time;

    time(&start_time); // Get start time
    printf("Starting process...\n");
    printf("Start time: %ld\n", start_time);

    // Simulate some work
    for (int i = 0; i < 100000000; i++);
    for (int i = 0; i < 2000000000; i++);

    time(&end_time); // Get end time
    printf("End time: %ld\n", end_time);

    elapsed_time = difftime(end_time, start_time);
    printf("Process finished in %.2f seconds.\n", elapsed_time);

    return 0;
}