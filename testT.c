#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;

    if (p == NULL) {
        printf("Pointer is NULL — it doesn’t point to anything.\n");
    }

    // Allocate memory
    p = (int*)malloc(sizeof(int));
    if (p != NULL) {
        *p = 42;
        printf("Value: %d\n", *p);
        free(p);
    }

    return 0;
}
