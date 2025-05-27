#include <stdio.h>

// *=== Variadic Macros ===*//
#define log(fmt, ...) printf("LOG: " fmt "\n", __VA_ARGS__)

int main()
{
    log("Hello, %s! You are %d years old.", "Ben", 25);

    return 0;
}