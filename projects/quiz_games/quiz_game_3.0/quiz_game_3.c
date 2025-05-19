#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_Q 100
#define MAX_LEN 100
#define QUESTIONS_TO_ASK 3 // This is a preprocessor directive in C. It tells the compiler: “Every time you see QUESTIONS_TO_ASK, replace it with 7 before compilation.”

typedef struct
{
    char question[MAX_LEN];
    char options[4][MAX_LEN];
    char answer;
} Quiz;

// Goal: Read quiz questions, options, and answers from a text file (e.g., "quiz.txt") and store them into an array of Quiz structs.
// Returns: The number of quiz questions successfully loaded.
int loadQuestionsFromFile(Quiz quizzes[], const char *filename)
{

    // Open the file
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        printf("Tried to open: %s\n", filename);
        return 0;
    }

    // Set up the loop
    int count = 0;

    // Reads each question one at a time using fgets().
    // fgets() stores one full line (including \n) into quizzes[count].question.
    // Loop continues until the end of the file.
    while (fgets(quizzes[count].question, MAX_LEN, file))
    {
        // Remove newline from question
        // This removes the trailing newline character (\n) that fgets() reads from the file.
        // Check @ txt --> 1.0
        quizzes[count].question[strcspn(quizzes[count].question, "\n")] = '\0'; // Remove newline

        //  Read the 4 options

        for (int i = 0; i < 4; i++)
        {
            // Reads the next 4 lines (each being one option: A, B, C, D). else?
            if (!fgets(quizzes[count].options[i], MAX_LEN, file))
            {
                fclose(file);
                return count; // Premature end
            }
            // Also strips off the newline at the end of each line using the same trick as with the question.
            quizzes[count].options[i][strcspn(quizzes[count].options[i], "\n")] = '\0';
        }

        // Read the answer
        char ansLine[MAX_LEN];
        // Reads the next line (e.g., B) which represents the correct answer. else?
        if (!fgets(ansLine, MAX_LEN, file))
        {
            fclose(file);
            return count; // No answer line
        }

        // Converts the answer to uppercase using toupper() for consistency.
        quizzes[count].answer = toupper(ansLine[0]); // Get first char as answer
        count++;

        // Skip blank line if any
        fgets(ansLine, MAX_LEN, file);
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
    int score = 0;

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

void shuffleQuestions(Quiz quizzes[], int total)
{
    srand(time(0)); // Seed the random generator

    // Fisher–Yates shuffle algorithm.
    // This is a for loop declaration, commonly used in C for reverse iteration — that is, looping from the end to the beginning of something (like an array).
    for (int i = total - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // Get a random index
        // First: int j = rand() % (i + 1);
        // 📌 What it does:
        // This line generates a random integer j between 0 and i (inclusive). Here's how:

        // 💡 Explanation:
        // rand() generates a pseudo-random integer between 0 and RAND_MAX (a large constant defined in stdlib.h).

        // % (i + 1) takes the remainder when dividing that random number by i + 1.

        // This effectively limits the range of values from 0 to i.

        // 🧠 Why i + 1?
        // Because % N returns values from 0 to N - 1. So to include i, you use i + 1.

        // Example:
        // If i = 4, then:
        // j = rand() % (4 + 1) = rand() % 5

        // Swap quizzes[i] and quizzes[j]
        Quiz temp = quizzes[i];
        quizzes[i] = quizzes[j];
        quizzes[j] = temp;
    }
}

void runQuiz(Quiz quizzes[], int totalQuestions)
{
    // Initialize local variables
    int score = 0;
    char entry;
    // char flush;

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
        scanf(" %c", &entry);
        // scanf("%c", &flush); // clear input buffer
        entry = toupper(entry);

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

int main()
{
    Quiz quizzes[MAX_Q];
    int total = loadQuestionsFromFile(quizzes, "quiz_3.txt");

    if (total > 0)
    {
        shuffleQuestions(quizzes, total); // <--- Shuffle questions retrived

        // Use the lesser of loaded questions or the fixed limit
        int questionsToRun = (total < QUESTIONS_TO_ASK) ? total : QUESTIONS_TO_ASK;

        runQuiz(quizzes, questionsToRun);
    }
    else
    {
        printf("No questions loaded.\n");
    }

    return 0;
}
