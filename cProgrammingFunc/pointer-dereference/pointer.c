#include <stdio.h>

void main01()
{
    // check @ notes for breakdown
    int num = 10;    // variable num with stored value 10
    int *ptr = &num; // store address of num in ptr

    printf("\n");
    printf("Value of the 'num' variable = %d.\n", num);
    printf("Address of 'num' variable = %p.\n", &num);
    printf("Address of pointer store/value = %p.\n", ptr);
    printf("Value at ptr (dereference): %d.\n", *ptr);

    *ptr = 50; // Dereference to modify the value at that address
    printf("New value of num: %d.\n", *ptr);
}

int main()
{

    main01();
    return 0; // Exit code
} // store address of num in ptr