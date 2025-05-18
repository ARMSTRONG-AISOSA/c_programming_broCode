// sleep_function.c
#include <stdio.h>
#include "pauseprogram.h" // Explicitly include the header

// Function defination
void pause_program(unsigned int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000); // Windows: milliseconds
#else
    sleep(seconds); // Unix-like: seconds
#endif
    printf("Program done");
}
