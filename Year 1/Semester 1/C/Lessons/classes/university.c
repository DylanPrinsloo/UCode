#include <stdio.h>
#include <string.h>

// University struct to represent the class
typedef struct {
    char name[50];
    int year;
} University;

// Constructor function for University
University createUniversity(const char *name, int year) {
    University u;
    strcpy(u.name, name);
    u.year = year;
    u.year = graduate(u);  // Call the private method equivalent
    return u;
}

// Method to display university details
void speak(University u) {
    printf("I am in the %s and I am in year %d\n", u.name, u.year);
}

// Getter for year
int getYear(University u) {
    return u.year;
}

// Setter for year
void setYear(University *u, int year) {
    u->year = year;
}

// Private method equivalent to 'graduate'
static int graduate(University u) {
    return u.year + 2;
}

int main() {
    // Create an object in main
    University micheal = createUniversity("tuks", 1900);
    speak(micheal);

    // Call setter
    setYear(&micheal, 2400);
    speak(micheal);

    // Access year via getter
    int year = getYear(micheal);
    printf("The current year is %d\n", year);

    return 0;
}

