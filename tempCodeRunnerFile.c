#include <stdio.h>
#include <string.h>

// Define enum for user roles
enum Role {
    ADMIN,
    EDITOR,
    VIEWER
};

// Define a struct for a user
struct User {
    char name[50];
    enum Role role;
};

// Function to print role name
void printRole(enum Role role) {
    switch (role) {
        case ADMIN:
            printf("Admin");
            break;
        case EDITOR:
            printf("Editor");
            break;
        case VIEWER:
            printf("Viewer");
            break;
        default:
            printf("Unknown");
    }
}

// Function to display user info
void displayUser(struct User u) {
    printf("User: %s | Role: ", u.name);
    printRole(u.role);
    printf("\n");
}

int main() {
    struct User user1 = {"Armstrong", ADMIN};
    struct User user2 = {"Ben", EDITOR};
    struct User user3 = {"Tony", VIEWER};

    displayUser(user1);
    displayUser(user2);
    displayUser(user3);

    return 0;
}
