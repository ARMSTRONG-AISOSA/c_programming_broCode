#include <stdio.h>

int main() {
    FILE *file_pointer;

    // Open a file named "my_data.txt" in write mode
    file_pointer = fopen("my_data.txt", "w");

    if (file_pointer == NULL) {
        printf("Error Opening file!\n");
        return 1;
    }

    printf("File opened successfully for writing.\n");

    // ... perform write operations using file_pointer ..

    fclose(file_pointer);// Remember to close the file!
    return 0;
}