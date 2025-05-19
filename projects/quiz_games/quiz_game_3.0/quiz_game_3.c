#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_Q 100
#define MAX_LEN 100

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

void runQuiz(Quiz quizzes[], int totalQuestions)
{
    // Initialize local variables
    int score = 0;
    char entry;
    // char flush;

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

    // Final Score
    printf("\n\033[1;36mFinal Score: %d/%d\033[0m\n", score, totalQuestions);
}

int main()
{
    Quiz quizzes[MAX_Q];
    int total = loadQuestionsFromFile(quizzes, "quiz_3.txt");

    if (total > 0)
    {
        runQuiz(quizzes, total);
    }
    else
    {
        printf("No questions loaded.\n");
    }

    return 0;
}
