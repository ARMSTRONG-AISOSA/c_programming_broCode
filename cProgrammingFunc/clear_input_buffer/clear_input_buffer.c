#include <stdio.h>

void clearInputBuffer();

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{

    int x;
    int valid;

    do
    {
        printf("Enter a number #(1-3): ");
        valid = scanf("%d", &x); // returns 1 only if a valid integer was entered

        if (valid != 1 || x < 1 || x > 3) // The expression(code) is true(hence runs) if valid is not 1, or if x is outside the range of [1, 3] (inclusive).
        {
            // printf("valid = %d\n", valid);
            printf("Invalid input. Row number must be between 1 and 3.\n");
            clearInputBuffer(); // clear leftover input -- letter input adds a new line
            valid = 0;          // force loop to repeat
            // Done because a number could be valid but not within 1-3
        }
    } while (!valid);

    // You might want to do something with the valid input 'x' here
    printf("You entered row number: %d\n", x);
    return 0;
}