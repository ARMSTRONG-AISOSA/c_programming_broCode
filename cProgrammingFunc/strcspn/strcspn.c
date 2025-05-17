#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[] = ",!";
    char str3[] = "xyz";
    char str4[] = "abcdefghijklmnopqrstuvwxyz";

    int len1 = strcspn(str1, str2);
    int len2 = strcspn(str1, str3);
    int len3 = strcspn(str1, str4);

    printf("strcspn(\"%s\", \"%s\") = %d\n", str1, str2, len1);
    printf("strcspn(\"%s\", \"%s\") = %d\n", str1, str3, len2);
    printf("strcspn(\"%s\", \"%s\") = %d\n", str1, str4, len3);

    return 0;
}