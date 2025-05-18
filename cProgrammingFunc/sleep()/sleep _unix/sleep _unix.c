#include <stdio.h>
#include <unistd.h> // For sleep()

int main() {
    printf("Start of program.\n");
    printf("Pausing for 5 seconds...\n");
    sleep(5); // Pause execution for 5 seconds
    printf("End of pause.\n");
    printf("Program continues.\n");
    return 0;
}