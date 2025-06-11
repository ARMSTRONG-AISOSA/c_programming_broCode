#include <stdio.h>

// Required for system() function (used in clearScreen)
#include <stdlib.h>

// Required for sleep() function on Unix-like system (Linux, macOS)
#ifndef _WIN32 // Only include if not on Windows
#include <unistd.h>
#endif

// Required for Sleep() function on Windows
#ifdef _WIN32 // Only include if on Windows
#include <windows.h>
#endif

// Function declarations (prototypes) - good practice!
void sleep_program(unsigned int seconds);
void clearScreen();

// Clear Screen(Terminal)
void clearScreen()
{
#ifdef _WIN32
    // For Windows
    system("cls");
#else
    // For Linux, macOS, and other POSIX-like systems
    system("clear");
#endif
}

void sleep_program(unsigned int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000); // Windows: milliseconds
#else
    sleep(seconds); // Unix-like: seconds
#endif
}

void test_1()
{
    printf("\n");
    printf("  /\\_/\\  \n");
    printf(" ( o.o ) \n");
    printf("  > ^ <  \n\n");
    printf("  Cat!   \n\n");
}

void test_2()
{
    printf("\n");
    printf("┌────────────────┐\n");
    printf("│    ASCII Art   │\n");
    printf("│       &        │\n");
    printf("│     Welcome    │\n");
    printf("│     to C!      │\n");
    printf("└────────────────┘\n");
    printf("\n");
}

void test_3()
{
    // This is an ascii art using a multiple stored amount of string in char; with multiple newline entry.
    char art[] =
        "    /\\   /\\\n"
        "   (  . .  )\n"
        "    )  _  (\n"
        "   (  (_)  )\n"
        "    ^^   ^^\n"
        "      Cat    ";

    printf("\n");
    printf("%s", art);
    printf("\n");
}

void test_4()
{
    // 2-d Array of strings
    char *banner[] = {
        "  ██████  \n",
        " ██    ██ \n",
        " ██    ██ \n",
        " ██    ██ \n",
        "  ██████  \n",
        NULL};

    banner[0];

    for (int i = 0; banner[i] != NULL; i++)
    {
        printf("%s", banner[i]);
    }

    // To test
    // printf("%s\n", banner[0]);
    // printf("%s\n", banner[1]);
    // printf("%s\n", banner[5]); // when printed; core memory dump
}

void test_5()
{
    // 2-d Array of strings
    char banner[7][25] = {
        " ███ ",
        "█   █",
        "    █",
        " ███ ",
        "█    ",
        "█    ",
        "█████"};

    banner[0];

    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", banner[i]);
    }

    // banner[i] by itself represents the i-th row of the banner array.
    // In C, when an array name (like banner[i], which is char[100]) is used in an expression where a pointer is expected, it "decays" into a pointer to its first element (char*).
    // After decvaying into a pointer; banner[i] correctly provides printf with a char* pointing to the beginning of the string on that row, allowing printf to print the entire string until it encounters the null terminator (\0).
}

void test_6()
{
    // multi-dimensional (3-d) array of strings.
    char *digits[6][7] = {
        // 0; index map to Ascii Art
        {
            " ███ ",
            "█   █",
            "█   █",
            "█   █",
            "█   █",
            "█   █",
            " ███ "},
        // 1
        {
            "  █  ",
            " ██  ",
            "  █  ",
            "  █  ",
            "  █  ",
            "  █  ",
            " ███ "},
        // 2
        {
            " ███ ",
            "█   █",
            "    █",
            " ███ ",
            "█    ",
            "█    ",
            "█████"},
        // 3
        {
            " ███ ",
            "█   █",
            "    █",
            " ███ ",
            "    █",
            "█   █",
            " ███ "},
        // 4
        {
            "█   █",
            "█   █",
            "█   █",
            "█████",
            "    █",
            "    █",
            "    █"},
        // 5
        {
            "█████",
            "█    ",
            "█    ",
            "████ ",
            "    █",
            "█   █",
            " ███ "},
    };

    // char *digits[6][7]; This means digits is an array of 6 elements, where each element is an array of 7 char* (pointers to strings).

    // Test
    // =====================================================================
    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%s\n", digits[0][i]);
    // }

    // printf("\n\n");

    // for (int i = 0; i < 7; i++)
    // {
    //     printf("%s\n", digits[4][i]);
    // }

    // =====================================================================

    // Loops through 6 elements (indexed = 0)
    // i.e iterates through each digit i want to print
    for (int i = 0; i < 6; i++)
    {
        // Add a blank line between different digits
        if (i > 0) // clever way to avoid add a newline from start
        {
            printf("\n");
        }

        // Loop through each line of the current digit's ASCII art
        // Psuedo: digits 0 - 6 has seven lines; char *digits[6][7]
        for (int j = 0; j < 7; j++) // Each digit has 7 lines of ASCII art
        {
            printf("%s\n", digits[i][j]);
        }

        // Notes:
        // char *digits[6][7]:
        // The first dimension of the array is [6] because the are 6 elements, the second dimension of the array is corrected to 7 because each digit's ASCII art has 7 lines.
    }
}

void test_7()
{
    // Dynamic ASCII Art
    // Animated banner:

    char frames[][100] = {
        "    o    ",
        "   /|\\   ",
        "   / \\   ",
        "",
        "    \\o/  ",
        "     |   ",
        "    / \\  "};

    for (int i = 0; i < 10; i++)
    {
        clearScreen();
        printf("%s\n", frames[0]);
        printf("%s\n", frames[1]);
        printf("%s\n", frames[2]);
        sleep_program(1);

        clearScreen();
        printf("%s\n", frames[4]);
        printf("%s\n", frames[5]);
        printf("%s\n", frames[6]);
        sleep_program(1);
    }
}

void test_8()
{
    // Reading ASCII Art from Files

    FILE *file = fopen("banner.txt", "r");
    char line[256];

    if (file != NULL) // excute if file is found
    {
        while (fgets(line, sizeof(line), file)) // Read text line (after text line)
        {
            printf("%s", line); // print Read/inputted text line
            sleep_program(1);
        }

        printf("\n");
        printf("\n All done. \n");
    }
}

void test_9()
{
    // Large ASCII Text
    // Creating big letters:

    printf("   ###   \n");
    printf("  #   #  \n");
    printf(" #     # \n");
    printf(" ####### \n");
    printf(" #     # \n");
    printf(" #     # \n");
}

int main()
{
    // test_1();
    // test_2();
    // test_3();
    // test_4();
    // test_5();
    // test_6();
    // test_7();
    // test_8();
    test_9();

    return 0;
}