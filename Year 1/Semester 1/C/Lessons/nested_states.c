#include <stdio.h>

int main() {
    int age;
    char food[50]; // Array to store the favorite food input

    printf("Input your age: ");
    scanf("%d", &age); // Read age from user input

    if (age >= 21) {
        printf("Input your favourite food: ");
        scanf("%s", food); // Read favorite food from user input

        // Check if the favorite food is pizza
        if (strcmp(food, "pizza") == 0) {
            printf("nice\n");
        } else {
            printf("Not pizza I guess\n");
        }
    } else if (age > 13 && age < 21) {
        printf("You are a teen\n");
    } else {
        printf("You are not a teen or an adult\n");
    }

    return 0; // Indicate successful completion
}
