#include <stdio.h>

// --- ANSI Escape Code Definitions ---
#define ANSI_BG_WHITE "\x1b[47m"    // background
#define ANSI_COLOR_BLACK "\x1b[30m" // text
#define ANSI_RESET "\x1b[0m"        // Reset to default

// Function to clear the screen (also using ANSI codes)
void clearScreenANSI()
{
    printf("\x1b[2J"); // Clear entire screen
    printf("\x1b[H");  // Move cursor to home position (top-left)
    fflush(stdout);    // Ensure changes are applied immediately
}

int main()
{
    // clearScreenANSI();

    printf("\n");
    printf("ANSI TESTING: \n");
    printf("\n");

    printf(ANSI_BG_WHITE ANSI_COLOR_BLACK "WHITE background and BLACK background.\n" ANSI_RESET);
}