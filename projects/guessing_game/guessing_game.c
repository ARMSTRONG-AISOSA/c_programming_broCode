
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessGame()
{
    // Number Guessing Game
    printf("\nFunction main38\n\n");

    const int MIN_NUM = 1;
    const int MAX_NUM = 100;

    int guess;
    int total_guesses;
    int answer;

    // seed
    srand(time(0));

    // generate a random number btw MIN_NUM & MAX_NUM
    answer = (rand() % MAX_NUM) + MIN_NUM;

    printf("Guess a number between %d and & %d.\n", MIN_NUM, MAX_NUM);

    // Use a do loop so the code runs the first time
    do
    {
        printf("Enter a guess: ");
        scanf("%d", &guess);

        if (guess > answer)
        {
            printf("Too High!\n");
        } else if (guess < answer) {
            printf("Too Low!\n");
        } 
        else {
            printf("Correct...🎉\n");
        }

        total_guesses++;
        
    } while (guess != answer);

    printf("*************************\n");
    printf("The answer is %d.\n", answer);
    printf("You guessed %d times.\n", total_guesses);
    printf("*************************\n");
}

int main() {
    guessGame();
}