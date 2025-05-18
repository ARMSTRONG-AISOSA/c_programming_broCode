#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main()
{
    printf("Start of program.\n");
#ifdef _WIN32
    printf("Windows like system...\n");
    printf("Pausing for 2 seconds...\n");
    Sleep(2000); // Windows: milliseconds
#else
    printf("Unix like system...\n");
    printf("Pausing for 2.5 seconds...\n");
    sleep(2.5); // Unix-like: seconds
#endif
    printf("End of pause.\n");
    printf("Program continues.\n");
    return 0;
}
