#include <stdio.h>
#include <stdlib.h>

int main()
{
    // calloc() = contiguous Allocation
    //  Alloactes memory dynamically and sets all allocated memory byte to zero.

    int number_of_players = 0;
    printf("Enter the number of players: ");
    scanf("%d", &number_of_players);
    printf("\n");

    int *player_scores = calloc(number_of_players, sizeof(int));

    if (player_scores == NULL)
    {
        printf("Memory allocation failed!");
        return 1; // Exit code for failed
    }
    else
    {
        for (int i = 0; i < number_of_players; i++)
        {
            printf("Enter the score number #%d: ", i + 1);
            scanf("%d", &player_scores[i]);
        }

        printf("\n");

        for (int i = 0; i < number_of_players; i++)
        {
            printf("The score #%d : %d\n", i+1, player_scores[i]);
        }
    }

    free(player_scores);
    player_scores = NULL;

    return 0;
}