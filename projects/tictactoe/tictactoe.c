#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Global variables
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';
const int ROW = 3;
const int COLUMN = 3;

// Function decleration
void resetBoard();
void printBoard();
int checkFreeSpaces();
void clearInputBuffer();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    // Local variable
    char winner = ' ';
    char response = ' ';
    char flush = ' ';

    do
    {
        // resetting winner and response
        winner = ' ';
        response = ' ';

        resetBoard(); // initialize all the caracters within our 2-D array

        while (winner == ' ' && checkFreeSpaces() != 0) // continues to run while both conditions are true. i.e while there is no winner and there are free space
        {
            printf("\033[1;36m\n🎮 Tic-Tac-Toe Starts Now 🎮\n\033[0m");
            printf("\033[34m=============================\033[0m\n\n");

            printBoard(); // print our board

            // Player move
            playerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break; // end code
            }

            // Computer move
            computerMove();
            winner = checkWinner();
            if (winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);

        // Play again ?
        printf("\n\033[33mWould you like to play again? (Y/N): \033[0m");
        scanf("%c", &flush); // clear (new line) buffer
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');

    printf("\nThanks for playing!\n\033[0m");

    return 0;
}

// Function defination
void resetBoard()
{
    for (int i = 0; i < ROW; i++) // row
    {
        for (int j = 0; j < COLUMN; j++) // column
        {
            board[i][j] = ' '; // index of 2-D array
        }
    }
};

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
};

int checkFreeSpaces()
{
    int freeSpaces = 9;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            // Code gets the no. of free spaces left
            if (board[i][j] != ' ') // minus one for every occupied space
            {
                freeSpaces--;
            }
        }

        return freeSpaces; // returning zero means they are no more spaces a player can play to
    }
};

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void playerMove()
{
    // entry variable
    int x;     // row number
    int y;     // column number
    int valid; // store scan function returned integer

    do
    {
        // Validate row number
        do
        {
            printf("\nEnter row number #(1-3): ");
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

        // Validate column number
        do
        {
            printf("\nEnter column number #(1-3): ");
            valid = scanf("%d", &y);

            if (valid != 1 || y < 1 || y > 3)
            {
                printf("Invalid input. Column number must be between 1 and 3.\n");
                clearInputBuffer();
                valid = 0;
            }
        } while (!valid);

        x--; // Adjust to 0-based index
        y--;

        // Now you can safely use x and y
        printf("You selected row %d and column %d.\n", x + 1, y + 1);

        if (board[x][y] != ' ') // if not empty
        {
            printf("Invalid move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }

    } while (board[x][y] != ' '); // repeat if the selected space is not empty
};

void computerMove()
{
    srand(time(0)); // seed random number
    int x, y;

    if (checkFreeSpaces() > 0) // Check if they are any more spaces
    {
        do
        {

            x = (rand() % 3); // range btw 0~2
            y = (rand() % 3);

        } while (board[x][y] != ' '); // repeat if the selected space is not empty

        board[x][y] = COMPUTER; // update board
    }
    else
    {
        printWinner(' '); // no winner; it's a draw
    }
};

char checkWinner()
{
    // check rows
    for (int i = 0; i < ROW; i++)
    {
        // If horizontal rows match
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0]; // return whatever character had the matching 3
        }
    }

    // check columns
    for (int i = 0; i < COLUMN; i++)
    {
        // If vertical columns match
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // check diagonals
    // #1
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    // #2
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    return ' '; // retruned if no winner
};

void printWinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("\n\033[1;32mYOU WIN!!!\033[0m\n");
    }
    else if (winner == COMPUTER)
    {
        printf("\n\033[1;31mYOU LOSE!\033[0m\n");
    }
    else
    {
        printf("\n\033[1;33mIT'S A TIE\033[0m\n");
    }
};
