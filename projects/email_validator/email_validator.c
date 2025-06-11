#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_email(const char *email)
{

    int at_found = 0;
    int dot_after_at = 0;
    int length = strlen(email);

    if (length < 5)
    {
        return 0; // Too short to be valid
    }

    for (int i = 0; i < length; i++)
    {
        if (email[i] == '@') // if @ is found
        {

            if (at_found == 1 || i == 0)
            {
                return 0; // multiple @ ||  starts with @(email[0] == @)
                // Already found before || found at position 1/index 0 character
            }

            at_found = 1;
        }
        else if (email[i] == '.' && at_found == 1)
        {
            if (dot_after_at == 1 || i == length - 1)
            {
                return 0; // multiple dot || dot at the end
                // Already found a dot before || dot as the end of the email
            }

            dot_after_at = 1;
        }
    }

    return at_found && dot_after_at; // return 1
}

int main()
{
    char email[100];

    printf("Enter your email address: ");
    if (fgets(email, sizeof(email), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1; // for error
    }

    // Remove newline character if present
    email[strlen(email) - 1] = '\0';

    int is_valid = is_valid_email(email); // Assign the result to is_valid 1 "OR" 0

    if (is_valid)
    {
        printf("✅ '%s' is a valid email.\n", email);
        // printf("Value: %d for true.\n", is_valid);
    }
    else
    {
        printf("❌ '%s' is not a valid email.\n", email);
        // printf("Value: %d for false.\n", is_valid);
    }

    return 0;
}
