// Check @ "ImportantToKnow" Custom String Extensions
// This is a custom reusable header file you can include in any C project to add your own versions of strlwr(), strupr(), and strrev().

#ifndef STRING_EXT_H
#define STRING_EXT_H

#include <ctype.h>  // for tolower(), toupper()
#include <string.h> // for strlen()

// Converts a string to lowercase (in-place)
char* strlwr(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
    return str;
}

// Converts a string to uppercase (in-place)
char* strupr(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
    return str;
}

// Reverses a string (in-place)
char* strrev(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return str;
}

#endif
