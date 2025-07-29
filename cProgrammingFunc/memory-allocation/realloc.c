#include <stdio.h>
#include <stdlib.h>

int main01()
{
    // realloc() = Reallocation and resizing(expand/shrink) of previously allocated memory.
    // realloc(ptr, bytes) ==> realloc(ptr to old mem., new size in bytes)

    int number_of_prices = 0;
    printf("Enter number of prices: ");
    scanf("%d", &number_of_prices);

    float *prices = malloc(number_of_prices * sizeof(float));

    if (prices == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < number_of_prices; i++)
    {
        printf("Enter the price for #%d : ", i + 1);
        scanf(" %f", &prices[i]); // Write to pointer addresses like its an array
    }

    printf("\n");

    for (int i = 0; i < number_of_prices; i++) // print entered prices
    {
        printf("The price for #%d : %.2f.\n", i + 1, prices[i]);
    }

    // -----------------------------------------//
    // Realloc Function: Ask to change the number of prices we have
    int new_number_of_prices = 0;
    printf("Enter a new number of prices: ");
    scanf("%d", &new_number_of_prices);

    float *temp = realloc(prices, new_number_of_prices * sizeof(float));

    if (temp == NULL)
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    else
    {
        prices = temp; // takes our pointer of "temp" and copies the new addres(es) over to "prices". Prices is now pointing to the new memory.
        // free(temp);
        temp = NULL; // Free up for reuse

        for (int i = 0; i < new_number_of_prices; i++)
        {
            printf("Enter the price for #%d : ", i + 1);
            scanf(" %f", &prices[i]); // Write to pointer addresses like its an array
        }

        printf("\n");

        for (int i = 0; i < new_number_of_prices; i++) // print entered prices
        {
            printf("The price for #%d : %.2f.\n", i + 1, prices[i]);
        }
    }
    // -----------------------------------------//

    free(prices);
    prices = NULL;

    return 0;
}

int main02()
{
    int number_of_houses = 0;
    printf("Enter number of Houses: ");
    scanf("%d", &number_of_houses);

    float *house_prices = malloc(number_of_houses * sizeof(float));

    if (house_prices == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < number_of_houses; i++)
    {
        printf("Enter the price for house #%d : ", i + 1);
        scanf(" %f", &house_prices[i]);
    }

    printf("\n");

    for (int i = 0; i < number_of_houses; i++)
    {
        printf("The price for #%d : %.2f.\n", i + 1, house_prices[i]);
    }

    // -----------------------------------------//
    // Realloc Function
    int new_number_of_houses = 0;
    printf("Enter a new number of prices: ");
    scanf("%d", &new_number_of_houses);

    float *temp = realloc(house_prices, new_number_of_houses * sizeof(float));

    if (temp == NULL)
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }
    else
    {
        house_prices = temp;
        // free(temp);
        temp = NULL; // Free up for reuse

        for (int i = number_of_houses; i < new_number_of_houses; i++)
        {
            printf("Enter the price for #%d : ", i + 1);
            scanf(" %f", &house_prices[i]); // Write to pointer addresses like its an array
        }

        printf("\n");

        for (int i = 0; i < new_number_of_houses; i++) // print entered prices
        {
            printf("The price for #%d : %.2f.\n", i + 1, house_prices[i]);
        }
    }
    // -----------------------------------------//

    free(house_prices);
    house_prices = NULL;

    return 0;
}

int main()
{
    // main01(); // Re-enter all prices after reallocation
    main02(); // Price re-entry based on memory reallocation/resize

    return 0;
}