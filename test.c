#include <stdio.h>

void birthday(const char *name, int age)
{
    for (int i = 0; i < 3; i++) {
        printf("Happy Birthday to %s!\n", name);
    }

    printf("You are now %d years old!\n", age);
    printf("Wishing you a wonderful year ahead, %s!\n", name);
}

int main()
{
    char name[50];
    int age;

    printf("Enter your name: ");
    scanf("%s", name);  // Note: this reads one word only (no spaces)

    printf("Enter your age: ");
    scanf("%d", &age);

    birthday(name, age);

    return 0;
}