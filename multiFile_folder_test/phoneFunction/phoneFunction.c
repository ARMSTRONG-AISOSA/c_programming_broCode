// Function Definition File
// This file impliments the function:

#include <stdio.h>
#include "../header/phoneHeader.h"

void phoneFunction(char name[], char memory[], int price, int releaseYear) {
    printf("\nThe phone is an %s. It is %s in memory size and it cost $%d. Its release year was %d.\n", name, memory, price, releaseYear );
}
