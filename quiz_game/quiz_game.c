#include <stdio.h>
#include <ctype.h>
#include "quiz_data.h" //pulls in our data

void quizGame()
{
    int numberOfQuestions = sizeof(questions) / sizeof(questions[0]);
    int option_size = 4;
    int question_size = 3;

    char entry, inputBuffer;
    int score = 0;

    printf("QUIZ GAME\n");
    printf("********************\n");

    for (int i = 0; i < numberOfQuestions; i++)
    {
        printf("%s\n", questions[i]);
        int option_start = option_size * i; // access options start point

        for (int j = 0; j < option_size; j++)
        {
            printf("%s\n", options[j + option_start]);
        }

        printf("Answer entry: ");
        scanf("%c", &entry);
        scanf("%c", &inputBuffer); //remove \n from input buffer

        entry = toupper(entry); // match letter cases

        if (entry == answers[i]) {
            printf("Correct 🎉\n");
            score++;
        } else {
            printf("Wrong Option!\n");
            printf("Ans = %c\n", answers[i]);
        }

        printf("********************\n");
    }

    printf("Total score: %d/%d.\n", score, question_size);
}

int main()
{
    quizGame();
    return 0;
}