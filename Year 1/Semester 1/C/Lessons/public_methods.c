#include <stdio.h>

void details(const char *n, const char *b, const char *c);

int main() {
    char name[50];        // Array to hold the name
    char surname[50];     // Array to hold the surname
    char studentId[20];   // Array to hold the student ID

    printf("Please enter your name: ");
    scanf("%s", name);   // Read name from user input

    printf("Please enter your surname: ");
    scanf("%s", surname); // Read surname from user input

    printf("Please enter your student ID: ");
    scanf("%s", studentId); // Read student ID from user input

    details(name, surname, studentId); // Call the details function

    printf("You have entered your details.\n");

    return 0; // Indicate successful completion
}

// Function to print the details
void details(const char *n, const char *b, const char *c) {
    printf("Hello %s %s. Your Student ID is: %s\n", n, b, c);
}

    }
    
