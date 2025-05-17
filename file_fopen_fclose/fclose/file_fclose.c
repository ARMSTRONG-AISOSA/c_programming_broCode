#include <stdio.h>

int main()
{
    FILE *file_pointer;

    // Open a file for writing || create one
    file_pointer = fopen("output.txt", "w");
    if (file_pointer == NULL)
    {
        perror("Error opening output.txt");
        return 1;
    }

    fprintf(file_pointer, "This is some data to write to the file.\n");

    // Close the file || error
    if (fclose(file_pointer) == EOF)
    {
        perror("Error closing output.txt");
        return 1;
    }

    printf("Data written to output.txt and the file is closed.\n");

    return 0;
}