#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Check @ notes
    //  malloc: A function in C that dynamically allocates a specific number of bytes in memory.

    int number_of_entries = 0;

    printf("Enter the number of grades: ");
    scanf("%d", &number_of_entries);

    //  The malloc function returns a pointer to the memory we just reserved, which we then store in "*grades"
    char *grades = malloc(number_of_entries * sizeof(char));

    // If address stored within grades is equal to NULL
    if (grades == NULL)
    {
        printf("Memory allocation failed");
        return 1; // exit code that there is a problem
    }
    else
    {

        for (int i = 0; i < number_of_entries; i++)
        {
            printf("Enter grade #%d: ", i + 1);
            // preceed %c to ignore white spaces
            // &grades:  address being written to
            // &grades[i]: with our pointer to array like data structure we can treat this like an array and access by index
            scanf(" %c", &grades[i]);
        }

        // Print each grade
        for (int i = 0; i < number_of_entries; i++)
        {
            // grades[i]; pointer to our grades at index of i
            printf("The grade #%d: %c.\n", i + 1, grades[i]);
        }
    }

    free(grades);  // Return/free up memory back to OS
    grades = NULL; // Reset pointer

    return 0;
}