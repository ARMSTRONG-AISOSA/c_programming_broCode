#include <stdio.h>
#include <unistd.h>  

int main() {
    FILE *fp = fopen("nonexistent_file.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    // ... rest of the code ...
    fclose(fp);
    return 0;
}