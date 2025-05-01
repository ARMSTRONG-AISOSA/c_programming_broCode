#include <stdio.h> //txt --> 1.0
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

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
    //Logical operators
    // && (AND) true-true
    printf("\nFunction main14\n\n");

    float temp1 = 30;
    bool sunny1 = true;

    if (temp1 >= 0 && temp1 <= 30 && sunny1 == true) {
        printf("The weather is warm and sunny.\n");
    } else if (temp1 < 0 && temp1 > -15) {
        printf("The weather is quite cold.\n");
    } else {
        printf("The weather is quite bad.\n");
    }

    // || (OR) Checks for atleast one true condition

    float temp2 = -10;

    if (temp2 >= 0 || temp2 <= 30 ) {
        printf("The weather is good\n");
    } else {
        printf("The weather is quite bad.\n");
    }

    // != (NOT) reverses the state of a condition

    bool sunny = false;

    if (!sunny) {
        printf("It is cloudy outside.\n");
    } else {
        printf("It is sunny outside.\n");
    }

}

void main15()
{

    printf("\nFunction main15\n\n");
}

void main16()
{

    printf("\nFunction main16\n\n");
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
    main14();
    return 0; // txt --> 3.1
}