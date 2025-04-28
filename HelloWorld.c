#include <stdio.h> //txt --> 1.0
#include <stdbool.h>

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


int main()
{
    main01();
    main02();
    main03();
    main04();
    return 0; // txt --> 3.1
}