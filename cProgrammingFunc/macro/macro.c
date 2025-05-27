#include <stdio.h>
#define PI 3.14159 //Object-like Macros
#define SQUARE(x) ((x) * (x)) //Function-like Macros

int main() {
    int result = SQUARE(10);
    printf("Result ans: %d\n", result);

    int r = 2;
    float area = PI * r * r;
    printf("Area ans: %f\n", area);

    return 0;
}