#include <stdio.h>

// Define an enum for days of the week
typedef enum {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
} Day;

// Function to demonstrate the use of enums
void printDayMessage(Day day) {
    switch (day) {
        case MONDAY:
            printf("Start of the work week!\n");
            break;
        case TUESDAY:
            printf("Second day of the work week.\n");
            break;
        case WEDNESDAY:
            printf("Midweek day.\n");
            break;
        case THURSDAY:
            printf("Almost the weekend.\n");
            break;
        case FRIDAY:
            printf("Last work day of the week!\n");
            break;
        case SATURDAY:
            printf("Weekend fun day!\n");
            break;
        case SUNDAY:
            printf("Rest and relaxation day.\n");
            break;
    }
}

int main() {
    // Demonstrating the use of enums
    printDayMessage(MONDAY);
    printDayMessage(FRIDAY);
    printDayMessage(SUNDAY);

    return 0;
}
