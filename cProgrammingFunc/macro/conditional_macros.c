#include <stdio.h>

// *=== Conditional Macros  ===*//
#define DEBUG

#ifdef DEBUG
#define log(msg) printf("DEBUG: %s\n\nI", msg)
#else
#define log(msg)
#endif

int main()
{

    // Conditional Macros
    log("This is a debug message");

    return 0;
}