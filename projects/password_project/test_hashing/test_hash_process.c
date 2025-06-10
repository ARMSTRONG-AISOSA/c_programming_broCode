#include <stdio.h>
#include <string.h>

unsigned int simple_hash_verbose(const char *password) {
    unsigned int hash = 5381;
    int c;
    int i = 0;

    printf("\nStarting hash value: %u\n", hash);

    while ((c = *password++)) {
        printf("Step %2d: char = '%c' (ASCII %d)\n", i + 1, c, c);
        printf("         Before: hash = %u\n", hash);
        printf("         hash = (hash * 33) + %d\n", c);
        hash = ((hash << 5) + hash) + c; // same as hash * 33 + c
        printf("         After:  hash = %u\n\n", hash);
        i++;
    }

    printf("Final hash value: %u\n", hash);
    return hash;
}

int main() {
    char password[50];

    printf("=== Step-by-Step Password Hashing ===\n");
    printf("Enter a string (max 49 characters): ");
    fgets(password, sizeof(password), stdin);

    // Remove trailing newline character if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    simple_hash_verbose(password);

    return 0;
}
