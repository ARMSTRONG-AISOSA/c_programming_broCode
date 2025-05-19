#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Sample array of 5 quiz IDs
    int quizzes[] = {1, 2, 3, 4, 5};
    int total = sizeof(quizzes) / sizeof(quizzes[0]);
    // int total = 3;

    printf("Original array:\n");
    printArray(quizzes, total);

    // Fisher-Yates shuffle
    for (int i = total - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // Random index between 0 and i

        // Print the indices to be swapped
        printf("Swapping index %d (value %d) with index %d (value %d)\n", i, quizzes[i], j, quizzes[j]);

        // Swap quizzes[i] and quizzes[j] -- basically swaping at randow whatever number comes
        int temp = quizzes[i];
        quizzes[i] = quizzes[j];
        quizzes[j] = temp;

        // Print array after swap
        printArray(quizzes, total);
    }

    printf("Shuffled array:\n");
    printArray(quizzes, total);

    return 0;
}
