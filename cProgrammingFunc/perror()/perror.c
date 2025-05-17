#include <stdio.h>
#include <errno.h>


int main() {
    FILE *fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        perror("Error Opening file");
        return 1;
    }

    // ... rest of the code ...

    fclose(fp);
    return 0;
}