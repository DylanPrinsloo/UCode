#include <stdio.h>
#include <string.h>

int main() {
    char s[100];  // Buffer to hold the input string

    // Taking input from the user
    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);  // Use fgets to read a line of input
    s[strcspn(s, "\n")] = '\0';   // Remove the newline character at the end if present

    // If-else statements for string comparison
    if (strcmp(s, "tim") == 0) {
        printf("The name is tim\n");
    } else if (strcmp(s, "hello") == 0) {
        printf("hello, You typed %s\n", s);
    } else {
        printf("You typed %s\n", s);
    }

    return 0;
}
