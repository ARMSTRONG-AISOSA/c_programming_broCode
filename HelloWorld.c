#include <stdio.h> //txt --> 1.0


void main01() {
    printf("I like pizza!\n");
    printf("\"It's really good shampoo\" -Jacob Thadeus\n");
    printf("\\Print backslashes\\\n");
}

void main02() {
    //txt --> 2.0
    printf("1\n2\n3\n");
    printf("1tab\t2tab\t3tab\n");
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
}


// === Lesson 4 Variables

void main03() {
//txt --> 4.0
int age = 23;
float gpa = 3.02; 
char grade = 'c';
char name[] = "Benson";

printf("Hello %s\n", name);
printf("I am %d years old.\n",age);
printf("Her English grade is %c.\n", grade);
printf("His gpa is %f.\n", gpa);
}





int main() {
    main01();
    main02();
    main03();
    return 0; //txt --> 3.1
}