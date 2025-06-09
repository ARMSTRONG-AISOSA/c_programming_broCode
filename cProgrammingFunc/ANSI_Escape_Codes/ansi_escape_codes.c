#include <stdio.h>

// --- ANSI Escape Code Definitions ---
// Text Colors (Foreground)
#define ANSI_COLOR_BLACK    "\x1b[30m"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_WHITE    "\x1b[37m"

// Bright Text Colors (Foreground)
#define ANSI_COLOR_BRIGHT_BLACK    "\x1b[90m"
#define ANSI_COLOR_BRIGHT_RED      "\x1b[91m"
#define ANSI_COLOR_BRIGHT_GREEN    "\x1b[92m"
#define ANSI_COLOR_BRIGHT_YELLOW   "\x1b[93m"
#define ANSI_COLOR_BRIGHT_BLUE     "\x1b[94m"
#define ANSI_COLOR_BRIGHT_MAGENTA  "\x1b[95m"
#define ANSI_COLOR_BRIGHT_CYAN     "\x1b[96m"
#define ANSI_COLOR_BRIGHT_WHITE    "\x1b[97m"

// Background Colors
#define ANSI_BG_BLACK      "\x1b[40m"
#define ANSI_BG_RED        "\x1b[41m"
#define ANSI_BG_GREEN      "\x1b[42m"
#define ANSI_BG_YELLOW     "\x1b[43m"
#define ANSI_BG_BLUE       "\x1b[44m"
#define ANSI_BG_MAGENTA    "\x1b[45m"
#define ANSI_BG_CYAN       "\x1b[46m"
#define ANSI_BG_WHITE      "\x1b[47m"

// Bright Background Colors
#define ANSI_BG_BRIGHT_BLACK    "\x1b[100m"
#define ANSI_BG_BRIGHT_RED      "\x1b[101m"
#define ANSI_BG_BRIGHT_GREEN    "\x1b[102m"
#define ANSI_BG_BRIGHT_YELLOW   "\x1b[103m"
#define ANSI_BG_BRIGHT_BLUE     "\x1b[104m"
#define ANSI_BG_BRIGHT_MAGENTA  "\x1b[105m"
#define ANSI_BG_BRIGHT_CYAN     "\x1b[106m"
#define ANSI_BG_BRIGHT_WHITE    "\x1b[107m"


// Text Attributes
#define ANSI_BOLD          "\x1b[1m"
#define ANSI_FAINT         "\x1b[2m" // Dim
#define ANSI_ITALIC        "\x1b[3m" // Not universally supported
#define ANSI_UNDERLINE     "\x1b[4m"
#define ANSI_BLINK         "\x1b[5m" // Not universally supported, annoying if it is
#define ANSI_INVERSE       "\x1b[7m" // Swap foreground and background
#define ANSI_HIDDEN        "\x1b[8m" // Invisible text
#define ANSI_STRIKETHROUGH "\x1b[9m" // Not universally supported

// Reset to default
#define ANSI_RESET         "\x1b[0m"

// Function to clear the screen (also using ANSI codes)
void clearScreenANSI() {
    printf("\x1b[2J"); // Clear entire screen
    printf("\x1b[H");  // Move cursor to home position (top-left)
    fflush(stdout);    // Ensure changes are applied immediately
}

int main() {
    clearScreenANSI(); // Start with a clean screen

    printf(ANSI_COLOR_GREEN "Hello, " ANSI_COLOR_BLUE "World!" ANSI_RESET "\n");
    printf(ANSI_BOLD ANSI_COLOR_YELLOW "This is a bold yellow message.\n" ANSI_RESET);
    printf(ANSI_UNDERLINE ANSI_COLOR_CYAN "Underlined cyan text.\n" ANSI_RESET);

    printf(ANSI_BG_RED ANSI_COLOR_WHITE "White text on a red background." ANSI_RESET "\n");
    printf(ANSI_BG_BRIGHT_BLUE ANSI_COLOR_BRIGHT_YELLOW "Bright yellow text on a bright blue background." ANSI_RESET "\n");

    // Combining multiple attributes
    printf(ANSI_BOLD ANSI_UNDERLINE ANSI_BG_MAGENTA ANSI_COLOR_BRIGHT_WHITE
           "ATTENTION: Bold, underlined, bright white on magenta!" ANSI_RESET "\n\n");

    // Displaying all standard colors
    printf("Standard Text Colors:\n");
    printf(ANSI_COLOR_BLACK "Black " ANSI_RESET);
    printf(ANSI_COLOR_RED "Red " ANSI_RESET);
    printf(ANSI_COLOR_GREEN "Green " ANSI_RESET);
    printf(ANSI_COLOR_YELLOW "Yellow " ANSI_RESET);
    printf(ANSI_COLOR_BLUE "Blue " ANSI_RESET);
    printf(ANSI_COLOR_MAGENTA "Magenta " ANSI_RESET);
    printf(ANSI_COLOR_CYAN "Cyan " ANSI_RESET);
    printf(ANSI_COLOR_WHITE "White " ANSI_RESET "\n");

    printf("Bright Text Colors:\n");
    printf(ANSI_COLOR_BRIGHT_BLACK "Bright Black " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_RED "Bright Red " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_GREEN "Bright Green " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_YELLOW "Bright Yellow " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_BLUE "Bright Blue " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_MAGENTA "Bright Magenta " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_CYAN "Bright Cyan " ANSI_RESET);
    printf(ANSI_COLOR_BRIGHT_WHITE "Bright White " ANSI_RESET "\n");

    printf("\nStandard Background Colors:\n");
    printf(ANSI_BG_BLACK ANSI_COLOR_WHITE " Black " ANSI_RESET); // White text for visibility
    printf(ANSI_BG_RED ANSI_COLOR_WHITE " Red " ANSI_RESET);
    printf(ANSI_BG_GREEN ANSI_COLOR_WHITE " Green " ANSI_RESET);
    printf(ANSI_BG_YELLOW ANSI_COLOR_BLACK " Yellow " ANSI_RESET); // Black text for visibility
    printf(ANSI_BG_BLUE ANSI_COLOR_WHITE " Blue " ANSI_RESET);
    printf(ANSI_BG_MAGENTA ANSI_COLOR_WHITE " Magenta " ANSI_RESET);
    printf(ANSI_BG_CYAN ANSI_COLOR_WHITE " Cyan " ANSI_RESET);
    printf(ANSI_BG_WHITE ANSI_COLOR_BLACK " White " ANSI_RESET "\n"); // Black text for visibility

    printf("\n");

    return 0;
}