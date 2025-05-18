// sleep_main.c
#include <stdio.h>
#include "pauseprogram.h" // Explicitly include the header

int main() {
    printf("Start of program.\n");
    printf("Pausing for 4 seconds using my_pause()...\n");
    pause_program(4); // Now the compiler knows about this function
    printf("\nEnd of pause.\n");
    printf("Program continues.\n");
    return 0;
}

// Run in directory terminal
// gcc sleep_main.c sleep_function.c -o sleepProgram