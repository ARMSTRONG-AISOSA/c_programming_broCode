#include <stdio.h>
// Check @ --> notes.txt

#define MY_MACRO // Define MY_MACRO
// #define ANOTHER_MACRO // Define ANOTHER_MACRO

int main()
{
#ifdef MY_MACRO
    printf("MY_MACRO is defined.\n"); // This will be printed
#endif

#ifndef ANOTHER_MACRO
    printf("ANOTHER_MACRO is not defined.\n"); // This will be printed
#endif

#ifndef MY_MACRO
    printf("This will not be printed.\n");
#endif

#ifdef ANOTHER_MACRO
    printf("This will not be printed.\n");
#endif
    return 0;
}