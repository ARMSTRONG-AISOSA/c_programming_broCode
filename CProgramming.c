#include <stdio.h> //txt --> 1.0
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "string_ext.h"

void main01()
{
    printf("\nFunction main01\n\n");
    printf("I like pizza!\n");
    printf("\"It's really good shampoo\" -Jacob Thadeus\n");
    printf("\\Print backslashes\\\n");
}

void main02()
{
    // txt --> 2.0
    printf("\nFunction main02\n\n");
    printf("1\n2\n3\n");
    printf("1tab\t2tab\t3tab\n");
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
}

// === Lesson 4 Variables
void main03()
{
    // txt --> 4.0 & 5.0
    // ps: signed => store neg. values
    int age = 23;
    float gpa = 3.02;
    double pie = 3.14159265358979323846;
    char grade = 'c';
    char name[] = "Benson"; // txt --> 5.1
    bool t = true;
    bool f = false;
    short int stInt = 32767;
    signed long long int lgLgInt = -1234567890987654321;
    long long int uLgLgInt = 1234567890987654321;

    printf("\nFunction main03\n\n");
    printf("Hello %s\n", name); // txt --> 5.2
    printf("I am %d years old.\n", age);
    printf("Her English grade is %c.\n", grade);
    printf("His gpa is %f.\n", gpa);
    printf("The value of pie printed with a double and long float %f.\n", pie);
    printf("The value of pie printed with a double, long float and 15 specified characters %0.15lf.\n", pie);
    printf("The boolean value is %d.\n", f);
    printf("The value of the short integer %d.\n", stInt);
    printf("The value of the long long integer %lld.\n", lgLgInt);
    printf("The value of the unsigned long long integer %llu.\n", uLgLgInt);
}

void main04()
{
    float item1 = 5.75;
    float item2 = 10.75;
    float item3 = 200.75;

    const float PI = 3.14159;

    printf("\nFunction main04\n\n");
    printf("Item 1: $%.2f.\n", item1);
    printf("Item 1: $%.2f, Item 2: $%.2f, Item 3: $%.2f.\n", item1, item2, item3);

    printf("The value of stored PI is %f.\n", PI);
}

void main05()
{
    // Arithmetic
    int x = 5;
    int y = 2;

    int multi = x * y;
    int add = x + y;
    int sub = x - y;
    float div = x / (float)y;
    int modulus = x % y;
    int incre = x++;
    int decre = y--;

    printf("\nFunction main05\n\n");
    printf("The mutipled figure is %d.\n", multi);
    printf("The added figure is %d.\n", add);
    printf("The subtracted figure is %d.\n", sub);
    printf("The divided figure is %f.\n", div);
    printf("The modulus figure is %d.\n", modulus);
    printf("The incremented number of x is %d.\n", x);
    printf("The decremented number of y is %d.\n", y);
}

void main06()
{
    // Augumented assignment operator
    // x = x+1
    // x+=1
    int a = 10;
    int b = 15;
    int c = 8;
    int d = 13;

    a += 2;
    b -= 5;
    c /= 4;
    d %= 2;

    printf("\nFunction main06\n\n");
    printf("Print% d.\n", a);
    printf("Print% d.\n", b);
    printf("Print% d.\n", c);
    printf("Print% d.\n", d);
}

void main07()
{
    // txt --> 6.0

    char firstName[50]; // bytes
    int age;
    char hobbies[100]; // bytes

    printf("\nFunction main07\n\n");

    printf("What is your first name?\n");
    scanf("%s", firstName); // Cannot handle white space

    printf("What is your age?\n");
    scanf("%d", &age); // txt --> 6.01
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // Clear the input buffer //txt --> 6.1
    // Search "getchar();" to see how for string array

    printf("What are your hobbies?\n");
    fgets(hobbies, 100, stdin);          // txt --> 6.2
    hobbies[strlen(hobbies) - 1] = '\0'; // txt --> 6.3

    printf("My name is %s and I am %d years old. My hobbies include %s.\n", firstName, age, hobbies);
}

void main08()
{
    // Math functions

    printf("\nFunction main08\n\n");

    double A = sqrt(9);
    double B = pow(2, 4);
    int C = round(3.14);
    int D = ceil(3.14);
    int E = floor(3.99);
    double F = fabs(-100);
    double G = log(3);
    double H = sin(45);
    double I = cos(45);
    double J = tan(45);

    printf("Square root math function = %lf.\n", A);
    printf("Raise to power math function = %lf.\n", B);
    printf("Round number math function = %d.\n", C);
    printf("Round up math function = %d.\n", D);
    printf("Round down math function = %d.\n", E);
    printf("Absolute number math function = %0.3lf.\n", F);
    printf("Log math function = %lf.\n", G);
    printf("Sine math function = %lf.\n", H);
    printf("Cosine math function = %lf.\n", I);
    printf("Tan math function = %lf.\n", J);
}

void main09()
{
    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nFunction main09\n\n");
    printf("Enter the radius of a circle:");
    scanf("%lf", &radius);

    // Cirumference Formula -> C = 2*π*r
    circumference = 2 * PI * radius;

    // Area Formula -> C = π*r(2)
    area = PI * radius * radius;

    printf("Circumference: %lf\n", circumference);
    printf("Area: %lf\n", area);
}

void main10()
{
    double A;
    double B;
    double C;

    printf("\nFunction main10\n\n");
    printf("Enter side A:");
    scanf("%lf", &A);

    printf("Enter side B:");
    scanf("%lf", &B);

    // Hypotenuse formula --> c(2) = a(2)+b(2)
    C = sqrt(A * A + B * B);

    printf("The hypothenuse is %lf\n.", C);
}

void main11()
{
    // If statements
    printf("\nFunction main11\n\n");

    int age;

    printf("Enter your age:");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are old enough to sign up.\n");
    }
    else if (age < 0)
    {
        printf("You haven't been born yet.\n");
    }
    else
    {
        printf("You are too young to sign up.\n");
    }

    // Switch = Asimiliar to "if else" and allows a value to be tested for equality against many cases.

    char grade;

    printf("Enter your grade:");
    scanf("%c", &grade);

    switch (grade)
    {
    case 'A':
        printf("Perfect Score.\n");
        break;
    case 'B':
        printf("You did well.\n");
        break;
    case 'C':
        printf("You did okay.\n");
        break;
    case 'D':
        printf("You barely passed.\n");
        break;
    case 'F':
        printf("You failed this course.\n");
        break;
    default:
        printf("Enter a valid grade.\n");
        break;
    }
}

void main12()
{
    // Temperature Conversion Program
    printf("\nFunction main12\n\n");

    float tempValue;
    char unit;
    float ansTemp;

    printf("Enter the temperature unit (C or F): ");
    scanf("%c", &unit);

    // Change the input to uppercase
    // unit = toupper(unit);

    printf("Enter the temperature value: ");
    scanf("%f", &tempValue);

    if (unit == 'C' || unit == 'c')
    {
        // C° to F°
        // added .0 to make the numbers floating and value accepted
        ansTemp = (tempValue * (9.0 / 5.0)) + 32;
        printf("The value %.2f°%c is %.2f°F.\n", tempValue, unit, ansTemp);
    }
    else if (unit == 'F' || unit == 'f')
    {
        // F° to C°
        ansTemp = (5.0 / 9.0) * (tempValue - 32);
        printf("The value %.2f°%c is %.2f°C.\n", tempValue, unit, ansTemp);
    }
    else
    {
        printf("Enter a valid unit.\n");
    }
}

void main13()
{
    // Calulator Program
    printf("\nFunction main13\n\n");

    double num1;
    double num2;
    double result;
    char operator;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter an operator (+ - / *): ");
    scanf(" %c", &operator); // Added a space before %c to consume the newline

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("The answer is %.3lf.\n", result);
        break;
    case '-':
        result = num1 - num2;
        printf("The answer is %.3lf.\n", result);
        break;
    case '/':
        result = num1 / num2;
        printf("The answer is %.3lf.\n", result);
        break;
    case '*':
        result = num1 * num2;
        printf("The answer is %.3lf.\n", result);
        break;
    default:
        printf("Enter a valid operator.\n");
        break;
    }
}

void main14()
{
    // Logical operators
    //  && (AND) true-true
    printf("\nFunction main14\n\n");

    float temp1 = 30;
    bool sunny1 = true;

    if (temp1 >= 0 && temp1 <= 30 && sunny1 == true)
    {
        printf("The weather is warm and sunny.\n");
    }
    else if (temp1 < 0 && temp1 > -15)
    {
        printf("The weather is quite cold.\n");
    }
    else
    {
        printf("The weather is quite bad.\n");
    }

    // || (OR) Checks for atleast one true condition

    float temp2 = -10;

    if (temp2 >= 0 || temp2 <= 30)
    {
        printf("The weather is good\n");
    }
    else
    {
        printf("The weather is quite bad.\n");
    }

    // != (NOT) reverses the state of a condition

    bool sunny = false;

    if (!sunny)
    {
        printf("It is cloudy outside.\n");
    }
    else
    {
        printf("It is sunny outside.\n");
    }
}

void birthday(char name[], int age) // txt --> 7.0 & 7.1
{
    printf("\nFunction Print Happy Birthday\n\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Happy Birthday to %s.🎉\n", name);
    }

    printf("You are now %d years old.\n", age);
    printf("Wishing you a wonderful year ahead, %s!\n", name);
}

void main15()
{
    // Function
    printf("\nFunction main15\n\n");

    char name[50];
    int age;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    birthday(name, age); // txt --> 7.1
}

double square(double x)
{
    double result;
    result = x * x;
    return result;
}

void main16()
{
    // The return function // txt --> 7.2
    printf("\nFunction main16\n\n");

    double value;
    double ans;

    printf("Enter the number you want squared: ");
    scanf("%lf", &value);

    ans = square(value);
    printf("The returned answer is %.2lf.\n", ans);
}

int findMax(int x, int y)
{
    // txt --> 7.2
    return (x > y) ? x : y;
}

void main17()
{
    // Ternary Operator
    printf("\nFunction main17\n\n");

    int value1;
    int value2;
    int X;

    printf("Enter an integer: ");
    scanf("%d", &value1);

    printf("Enter an integer: ");
    scanf("%d", &value2);

    X = findMax(value1, value2);
    printf("The maximum number is %d.\n", X);
}

// Function prototype
void greetUser(char name[], int age);

void main18() // txt --> 7.3
{
    printf("\nFunction main18\n\n");

    greetUser("Armstrong", 26); // txt --> 7.3.1
}

// Function defination
void greetUser(char name[], int age)
{
    printf("Hello %s,\nYou are %d years old today.\n", name, age);
}

void main19()
{
    // String Functions
    // Check @ "ImportantToKnow" Custom String Extensions
    printf("\nFunction main19\n\n");

    char string1[] = "Bro";
    char string2[] = "Code";
    char string3[] = "Apple";

    strlwr(string1); // convert string to lowercase

    printf("lower: %s\n", string1);
    printf("upper: %s\n", strupr(string2));
    printf("Reverse: %s\n", strrev(string3));
}

void main20()
{
    // Loops == txt --> 8.0
    printf("\nFunction main20\n\n");

    // for loop
    for (int i = 1; i <= 5 && i > 0; i++)
    {
        printf("1st test %d\n", i);
    };

    printf("\n");

    for (int i = 50; i >= 0; i = i - 10)
    {
        printf("2nd test %d\n", i);
    };

    // while loop
    char name[25];

    printf("\nWhat's your name?: ");
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';

    while (strlen(name) == 0)
    {
        printf("\nEnter your name");
        printf("\nWhat's your name?: ");
        fgets(name, 25, stdin);
        name[strlen(name) - 1] = '\0';
    }

    printf("Hello %s\n", name);

    // do while loop
    int number = 0;
    int sum = 0;

    do
    {
        printf("\nEnter a number above 0: ");
        scanf("%d", &number);
        if (number > 0)
        {
            sum = sum + number;
        }
    } while (number > 0);

    printf("\nThe sum total is %d.\n", sum);
}

void main21()
{
    // nested loops: a loop inside of another
    printf("\nFunction main21\n\n");

    int rows;
    int columns;

    printf("Enter a # of rows: ");
    scanf("%d", &rows);

    printf("Enter a # of columns: ");
    scanf("%d", &columns);

    for (int i = 1; i <= rows; i++)
    {
        printf("Row %d: ", i);
        for (int j = 1; j <= columns; j++)
        {
            printf("col:%d ", j);
        };
        printf("\n");
    }

    printf("Program Completed!\n");
}

void main22()
{
    // Break vs Continue
    printf("\nFunction main22\n\n");

    // continue = skips an iteration (code) and moves on to the next iteration of a loop
    printf("Continue Statement\n");
    for (int i = 1; i <= 20; i++)
    {
        if (i == 3 || i == 10 || i == 13)
        {
            printf("We skipped %d\n", i);
            continue;
        }
        else if (i == 18)
        {
            printf("We skipped %d\n", i);
            continue;
        }
        else
        {
            printf("The current iteration is %d\n", i);
        }
    }

    // break = exit a loop/switch
    printf("\nBreak Statement\n");
    for (int i = 1; i <= 8; i++)
    {
        if (i == 3)
        {
            printf("\nWe exit the loop at %d iteration\n", i);
            break;
        }
    }
}

void main23()
{
    // Array == txt --> 8.0
    printf("\nFunction main23\n\n");

    // Initialize & declaar size
    double prices[10] = {5.05, 11.22, 14.48, 7.65, 6.78};

    // print specific
    printf("$%.2lf\n\n", prices[2]);

    // print all
    for (int i = 0; i < 10; i++)
    {
        printf("The price at index no. %d is $%.2lf.\n", i, prices[i]);
    }

    // add to array
    prices[6] = 4.08;
    printf("\nThe newly added price is $%.2lf\n\n", prices[6]);

    // update array
    prices[0] = 51.08;
    printf("\nThe updated price is $%.2lf\n\n", prices[0]);

    // String Array == txt --> 8.1
    char letters[] = {'J', 'K', 'T'};
    printf("The letter %c\n\n", letters[0]);

    // String Array (indirect - 2D Array of Strings)
    char *names[] = {"James", "Ken", "Tony"};
    printf("%s\n", names[0]);

    // String Array (2D Array of Strings)
    char nameList[3][10] = {
        "James",
        "Ken",
        "Tony"};
    printf("%s\n\n", nameList[1]);
    // print all name
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", nameList[i]);
    }
}

void main24()
{
    // Array Strings with inputs
    printf("\nFunction main24\n\n");

    // Example #1
    char fruits[4][20]; // Store 3 names, max 19 characters each (+1 for '\0')

    printf("Enter 4 fruit names.\n");

    for (int i = 0; i < 4; i++)
    {
        printf("#%d is: ", i + 1);
        scanf("%19s", fruits[i]); // Limit input size to avoid buffer overflow
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Fruit %d: %s.\n", i + 1, fruits[i]);
    }

    // Example #2: accept spaces in name
    char fullNames[3][50]; // Array to store 3 names, each up to 49 characters

    printf("Enter 3 full names:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Fullname %d: ", i + 1);
        fgets(fullNames[i], sizeof(fullNames[i]), stdin);

        // Remove trailing newline from fgets
        fullNames[i][strcspn(fullNames[i], "\n")] = '\0';
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name %d : %s.\n", i + 1, fullNames[i]);
    }
}

void main25()
{
    // Dynamic Array of Names (User Chooses How Many)
    printf("\nFunction main25\n\n");

    int count;
    printf("How many items do you want to enter? :");
    scanf("%d", &count);
    getchar(); // Clear leftover newline from input buffer

    // Allocate array of string pointers
    char **items = malloc(count * sizeof(char *));

    for (int i = 0; i < count; i++)
    {
        items[i] = malloc(100 * sizeof(char)); // Allocate 100 chars for each item name

        printf("Enter item name %d: ", i + 1);
        fgets(items[i], 100, stdin);
        items[i][strcspn(items[i], "\n")] = '\0'; // Remove trailing newline
    }

    printf("\nYou entered:\n");
    for (int i = 0; i < count; i++)
    {
        printf("    Item %d: %s.\n", i + 1, items[i]);
        free(items[i]); // Free memory for each item name
    }

    free(items); // free the array of pointers
}

void main26()
{
    // Loop through the elements of an array(intuiive condition)
    printf("\nFunction main26\n\n");

    // Ex. 1
    double priceTags[] = {2.50, 8.75, 4.55, 7.35, 6.05};

    // check @ txt --> 10.0 for full explanation
    printf("The size of the array is %zu bytes and size of each element in the array is %zu.\nDivide the former by the latter and you have %zu elements.\n",
           sizeof(priceTags),
           sizeof(priceTags[0]),
           sizeof(priceTags) / sizeof(priceTags[0]));

    for (int i = 0; i < sizeof(priceTags) / sizeof(priceTags[0]); i++)
    {
        printf("#%d price: %.2lf.\n", i + 1, priceTags[i]);
    }

    // Ex. 2
    // NB: char *ingredients[] is an array of pointers to string literals.
    // Since i can't write char[3][10] here.
    char *ingredients[] = {"Tomatoes", "Spaghetti", "Spices", "Oil", "Vegitable", "Meat", "Maggi"};

    printf("\n\nThe size of the array %zu is and the size of each element is %zu.\nThe number of elements is then %zu.\n",
           sizeof(ingredients),
           sizeof(ingredients[0]),
           sizeof(ingredients) / sizeof(ingredients[0]));

    for (int i = 0; i < sizeof(ingredients) / sizeof(ingredients[0]); i++)
    {
        printf("Ingredient %d, :%s.\n", i + 1, ingredients[i]);
    }
}

void main27()
{
    // 2D array =an array where each element ia an entire array, useful for matrix, grid or table of data
    printf("\nFunction main27\n\n");

    // Ex. 1
    int numbers[2][3] = {
        {1, 2, 3},
        {4, 5, 6}}; // 2 rows by 3 columns array

    // print all element in a 2d array
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) // loop through rows
    {
        for (int j = 0; j < sizeof(numbers[2]) / sizeof(numbers[0][0]); j++) // loop through columns
        {
            printf("Row index[%d] of column index[%d] = %d\n", i, j, numbers[i][j]);
        }
    }

    // to change
    numbers[0][0] = 33;  // first row by frist column
    numbers[1][2] = 110; // second row by third column
}

void main28()
{
    // Array of strings - is actually a 2d array
    printf("\nFunction main28\n\n");

    char luxuryBrands[][20] = {"Gucci", "Lamborghini", "Channel", "Corvette"};

    for (int i = 0; i < sizeof(luxuryBrands) / sizeof(luxuryBrands[0]); i++)
    {
        printf("The %d item is %s.\n", i + 1, luxuryBrands[i]);
    }

    // You cannot directly change values in the array but you can use the string copy function to solve this.
    // ❌luxuryBrand[0] = "Tesla";

    strcpy(luxuryBrands[0], "Gabana");

    printf("\nThe update item %d is %s.\n", 1, luxuryBrands[0]);
}

void main29()
{
    // Swap values of two variables - useful for sorting algorithms
    printf("\nFunction main29\n\n");

    // Ex. 1
    char x = 'X';
    char y = 'Y';
    char tempHolder;

    printf("The value of x = %c and the value of y = %c.\n", x, y);

    tempHolder = x;
    x = y;
    y = tempHolder;

    printf("After the swap the value of x = %c and the value of y = %c.\n\n", x, y);

    // Ex. 2
    char drink1[10] = "Coke";
    char drink2[10] = "Fanta";
    char temporaryCup[10];

    printf("The first cup drink is %s and the second cup drink is %s.\n", drink1, drink2);

    // For arrays you have to use the string-copy-function(strcpy)
    // Ps: Make all arrays same size to prevent some issues
    strcpy(temporaryCup, drink1); // pour coke into temporary cup
    strcpy(drink1, drink2);       // pour fanta into the first drink cup
    strcpy(drink2, temporaryCup); // pour the coke from the temporary cup into the second cup

    printf("After the stwitch, the first cup drink is %s and the second cup drink is %s.\n", drink1, drink2);
}

void bubbleSortInt(int array[], int sizeOfArray)
{
    // PS: Bubble Sort is not efficient for large datasets.
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        // Controls how many passes through the array you make.
        // Check @ txt --> 11.0
        // printf("pass %d (i = %d)\n", i + 1, i);
        for (int j = 0; j < sizeOfArray - 1; j++)
        {
            // printf("  ~Compare %d and %d\n", array[j], array[j + 1]);
            // If element on left is greater than the right swap them
            if (array[j] > array[j + 1])
            {
                int tempHolder = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempHolder;
            }
        }
    }
}

void printNumArray(int array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void main30()
{
    // Sort an Array of Integers
    printf("\nFunction main30\n\n");

    int numArray[] = {2, 7, 1, 8, 4, 5, 6, 9, 0, 3};
    int numArraySize = sizeof(numArray) / sizeof(numArray[0]);

    // Bubble Sort Array
    bubbleSortInt(numArray, numArraySize);

    // Print (Sorted )Array
    printNumArray(numArray, numArraySize);
}

void bubbleSortLetter(char array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        for (int j = 0; j < sizeOfArray - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printLetterArray(char array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");
}

void main31()
{
    // Sort an Array of Letters
    printf("\nFunction main31\n\n");

    char letterArray[] = {'C', 'F', 'Y', 'H', 'M', 'G', 'A', 'a', 'B'};
    int letterArraySize = sizeof(letterArray) / sizeof(letterArray[0]);

    // Bubble Sort
    bubbleSortLetter(letterArray, letterArraySize);

    // Print Array
    printLetterArray(letterArray, letterArraySize);
}

struct Player
{
    char name[30];
    int score;
};

struct PhoneData
{
    char name[40];
    char model[25];
    int price;
    int releaseYear;
};

void main32()
{
    // Struct -- Check @ txt --> 12
    printf("\nFunction main32\n\n");

    // Ex. 1
    struct Player player1;
    struct Player player2;
    struct Player player3 = {"Ovie James", 9};

    strcpy(player1.name, "Omoregie Armstrong"); // Use string copy for arrays
    player1.score = 7;                          // you can write to string directly

    strcpy(player2.name, "Omoregie Harmony");
    player2.score = 8;

    printf("Player 1 name: %s and score: %d.\n", player1.name, player1.score);
    printf("Player 2 name: %s and score: %d.\n", player2.name, player2.score);
    printf("Player 3 name: %s and score: %d.\n\n", player3.name, player3.score);

    // Ex. 2
    struct PhoneData phone1;
    struct PhoneData phone2;
    struct PhoneData phone3 = {
        "Samsung Galaxy S24 Ultra",
        "SM-S928B",
        1199,
        2014};

    strcpy(phone1.name, "iPhone 15 Pro Max");
    strcpy(phone1.model, "A2849");
    phone1.price = 1199;
    phone1.releaseYear = 2023;

    strcpy(phone2.name, "Google Pixel 8 Pro");
    strcpy(phone2.model, "GC3VE");
    phone2.price = 999;
    phone2.releaseYear = 2023;

    // Phone 1
    printf("The brand is a %s, model %s.\nIt has a price tag of $%d and the release year is %d.\n\n", phone1.name, phone1.model, phone1.price, phone1.releaseYear);
    // Phone 2
    printf("The brand is a %s, model %s.\nIt has a price tag of $%d and the release year is %d.\n\n", phone2.name, phone2.model, phone2.price, phone2.releaseYear);
    // Phone 3
    printf("The brand is a %s, model %s.\nIt has a price tag of $%d and the release year is %d.\n\n", phone3.name, phone3.model, phone3.price, phone3.releaseYear);
}

// learn step #1
typedef char user[25]; // A character array of 25bytes nicknamed user

// learn step #2 (without typedef)
struct UserData
{
    char name[25];
    char password[12];
    int id;
};

// learn step #2 (with typedef)
typedef struct
{
    char name[30];
    char password[12];
    int id;
    char gender[7];
    char role[25];
} StaffData;

void main33()
{
    // typedef = (reserved keyword that) gives an existing datatype a "nickname"
    printf("\nFunction main33\n\n");

    // learn step #1
    // Array variable without typedef
    char user1[25] = "Montana"; // A chracter array of 25 bytes

    // with typedef
    user user2 = "Kilogram"; // A character array of 25 bytes assigned with the typedef nickname user; variable name "user2"

    user user3 = "Canada";

    printf("Two character array of 25 bytes called %s & %s.\n\n", user2, user3);

    // learn step #2
    // struct without typedef
    struct UserData person1 = {"Churchill Jekkins", "#P@ssw0rds", 123000};
    struct UserData person2 = {"Jamal Jekkins", "@Sw0rdSw0rd", 123100};

    printf("A person1 data of \nName: %s\nPassword: %s\nId: %d.\n\n", person1.name, person1.password, person1.id);

    // struct with typedef
    StaffData employee1 = {
        "Charles Babage",
        "password456",
        123450,
        "Male",
        "I.T Assitant"};

    StaffData employee2 = {
        "James Babage",
        "passwo678456",
        123449,
        "Male",
        "I.T Lead"};

    printf("An employee1 data of \nName: %s\nPassword: %s\nId: %d\nGender: %s\nRole: %s\n\n", employee1.name, employee1.password, employee1.id, employee1.gender, employee1.role);
}

void main34()
{
    // Array of struct
    printf("\nFunction main34\n\n");
}

int main()
{
    // main01();
    // main02();
    // main03();
    // main04();
    // main05();
    // main06();
    // main07();
    // main08();
    // main09();
    // main10();
    // main11();
    // main12();
    // main13();
    // main14();
    // main15();
    // main16();
    // main17();
    // main18();
    // main19();
    // main20();
    // main21();
    // main22();
    // main23();
    // main24();
    // main25();
    // main26();
    // main27();
    // main28();
    // main29();
    // main30();
    // main31();
    // main32();
    // main33();
    main34();
    return 0; // txt --> 3.1
}

void main35()
{

    printf("\nFunction main35\n\n");
}

void main36()
{

    printf("\nFunction main36\n\n");
}

void main37()
{

    printf("\nFunction main37\n\n");
}

void main38()
{

    printf("\nFunction main38\n\n");
}

void main39()
{

    printf("\nFunction main39\n\n");
}

void main40()
{

    printf("\nFunction main40\n\n");
}

void main41()
{

    printf("\nFunction main41\n\n");
}