// quiz_utils.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "quiz_utils.h" //decleared functions

// Check @ txt --> 3.0
int load_questions_from_file(QuizStruct quizzes[], const char *filename)
{
    printf("Entering load_questions_from_file with filename: %s\n", filename); // Add this line to debug

    // Open the file
    FILE *file = fopen(filename, "r");

    if (!file) // If file doesn't open
    {
        perror("Failed to open file");
        printf("Tried to open: %s\n", filename);
        return 0;
    }

    // set up loop
    int count = 0;

    // Reads each question one at a time using fgets().
    // Loop continues until the end of the file to remove trailing spaces from stored questions
    while (fgets(quizzes[count].question, QUESTION_ARRAY_SIZE, file))
    {
        // Check @ txt --> 1.0
        quizzes[count].question[strcspn(quizzes[count].question, "\n")] = '\0'; // Remove newline

        // Read the 4 options
        // Loop continues until the end of the file to remove trailing spaces from stored options
        for (int i = 0; i < 4; i++)
        {
            // Reads the next 4 lines (each being one option: A, B, C, D). else?
            if (!fgets(quizzes[count].options[i], INDIVIDUAL_OPTION_ARRAY_SIZE, file))
            {
                fclose(file);
                return count; // Premature end
            }

            // Remove newline
            quizzes[count].options[i][strcspn(quizzes[count].options[i], "\n")] = '\0';
        }

        // Read the answer
        char answerLine[ANSWER_ARRAY_SIZE];
        if (!fgets(answerLine, ANSWER_ARRAY_SIZE, file))
        {
            fclose(file);
            return count; // No answer line
        }

        // Convert the answer from the file to uppercase
        quizzes[count].answer = toupper(answerLine[0]); // Get first char as answer
        count++;

        // Skip blank line if any
        fgets(answerLine, ANSWER_ARRAY_SIZE, file);
    }

    // After loop: close file and return count
    // Properly closes the file.
    fclose(file);
    // Returns the number of quiz questions successfully loaded.
    return count;
}

int readHighScore(const char *filename)
{
    FILE *file = fopen(filename, "r");
    int score = 0; // initialize score variable

    // If file exist
    if (file)
    {
        fscanf(file, "%d", &score);
        fclose(file);
    }

    return score;
}

void saveHighScore(const char *filename, int score)
{
    FILE *file = fopen(filename, "w");

    // If file exist
    if (file)
    {
        fprintf(file, "%d", score);
        fclose(file);
    }
}

// Check @ txt --> 4.0
void shuffle_quizzes(QuizStruct quizzes[], int total)
{
    srand(time(0)); // Seed the random generator

    // Fisher–Yates shuffle algorithm.
    // This is a for loop declaration, for reverse iteration i.e from the end to the beginning of an array.
    // Check @ txt --> 2.0
    for (int i = total - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // Get a random index
        // This line generates a random integer j between 0 and i (inclusive).
        // Check @ txt --> 2.0

        // Swap quizzes[i] and quizzes[j]
        QuizStruct temp = quizzes[i];
        quizzes[i] = quizzes[j];
        quizzes[j] = temp;
    }
}

// Check @ txt --> 5.0
void run_quiz(QuizStruct quizzes[], int totalQuestions)
{
    // Initialize local variables
    int score = 0;
    char entry;

    // ⏱ Start timing
    time_t start_time, end_time;
    double total_time;
    time(&start_time); // record start time

    const char *highScoreFile = "highscore.txt";
    int highScore = readHighScore(highScoreFile);

    printf("\033[1;36m\n🎮 QUIZ GAME STARTS NOW 🎮\n\033[0m");
    printf("\033[34m=============================\033[0m\n");

    // Loops through each quiz question loaded into the quizzes array.
    for (int i = 0; i < totalQuestions; i++)
    {
        // Display the question
        printf("\n\033[33m%s\033[0m\n", quizzes[i].question);

        // Display the 4 options
        for (int j = 0; j < 4; j++)
        {
            printf("%s\n", quizzes[i].options[j]);
        }

        // Prompt for user input
        printf("\033[35mAnswer entry: \033[0m");
        scanf(" %c", &entry); // a space before %c which is good for consuming any leading whitespace (like newline characters from previous inputs).
        entry = toupper(entry);

        // If entry is 'A', 'B', 'C', or 'D', the expression evaluates to false, meaning the input is valid.
        if (entry < 'A' || entry > 'D')
        {
            printf("\033[1;33;41mInvalid input. Please enter A, B, C, or D.\33[0m\n");

            // printf("\033[1;33;41mWarning!!!\33[0m\n");
            i--;      // Repeat this question
            continue; // skips the rest of the current iteration and restarts the loop.
            // PS: Invalid inputs are caught before they're evaluated against the correct answer.
            // If the user enters 'E', 'Z', '1', 'x', '#', or any other character outside the range 'A' to 'D', the condition becomes true.
        }

        // Check if the answer is correct
        if (entry == quizzes[i].answer)
        {
            printf("\033[32mCorrect 🎉\033[0m\n");
            score++;
        }
        else
        {
            printf("\033[31mWrong ❌! Correct Answer: %c\033[0m\n", quizzes[i].answer);
        }

        // Print a separator
        printf("\033[34m-----------------------------\033[0m\n");
    }

    // ⏱ End timing
    time(&end_time);                             // record end time
    total_time = difftime(end_time, start_time); // calculate difference

    // Final Score
    printf("\n\033[1;36mFinal Score: %d/%d\033[0m\n", score, totalQuestions);
    // Total Time
    printf("\033[36mTotal time: %.2lf seconds.\033[0m\n", total_time);

    // Highscore
    if (score > highScore)
    {
        printf("\033[1;32m🎉 New High Score! Saving... \033[0m\n\n");
        saveHighScore(highScoreFile, score);
    }
    else if (score == highScore)
    {
        printf("\033[1;33mYou matched the current high score.\033[0m\n\n");
    }
    else
    {
        printf("\033[1;33mYou didn't beat the high score: %d. Try again!\033[0m\n\n", highScore);
    }
}
