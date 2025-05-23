// quiz_game_4.0.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "constants.h"      //Constants
#include "quiz_structure.h" //Quiz structure
#include "quiz_utils.h"     //decleared functions

// Check @ txt --> 4.0
int main()
{
    printf("Entering main function.\n"); // Add this line

    QuizStruct quizzes[QUIZ_ARRAY_SIZE]; // Struct Quiz array; decleared and passed to the function

    int totalQuestions = load_questions_from_file(quizzes, "quiz_4.txt"); // Total number of questions is returned by the functions once it's done running

    printf("Returned from load_questions_from_file. Total questions: %d\n", totalQuestions); // Add this line to debug

    if (totalQuestions > 0) // run if total returned questions is greater than zero
    {
        printf("Run shuffle code of total quiz\n"); // Add this line to debug

        shuffle_quizzes(quizzes, totalQuestions); // shuffle retrived quiz data

        printf("Done!\n"); // Add this line to debug

        // Use the lesser of loaded quiz data or fixed limit
        int questionsToRun = (totalQuestions < NUM_OF_QUESTIONS_TO_ASK) ? totalQuestions : NUM_OF_QUESTIONS_TO_ASK;

        printf("Run Quiz program.\n"); // Add this line to debug
        run_quiz(quizzes, questionsToRun);
    }
    else
    {
        printf("No questions loaded.\n");
    }

    return 0;
}

// To run this code
// gcc quiz_game_4.0.c quiz_utils.c -o quiz_game_4.0 -lm
//./quiz_game_4.0
// -lm: adds math lib