#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
// #include <windows.h> // Windows pc

int main()
{
    // Check @ system_buffer.txt for context
    printf("Start of program.\n");
    sleep(1);
    printf("Loading 6...");
    sleep(1);
    printf("5...");
    sleep(1);
    printf("4...");
    sleep(1);
    printf("\n3...\n");
    sleep(1);
    printf("2..\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("End of program.\n");

    return 0;
}

// Run in directory terminal
// gcc c_digital_clock.c sleep_function.c -o digital_clock
// ./digital_clock