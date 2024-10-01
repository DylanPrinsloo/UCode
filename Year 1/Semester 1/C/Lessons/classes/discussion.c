#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int year;
} University;

// Function to print university details
void speak(University u) {
    printf("University: %s, Established Year: %d\n", u.name, u.year);
}

// Getter for the year
int getYear(University u) {
    return u.year;
}

// Setter for the year
void setYear(University *u, int newYear) {
    u->year = newYear;
}

// Private method (can't be called from main, only shown here for example)
// static void graduate(University u) {
//     printf("%s has graduated!\n", u.name);
// }

int main() {
    // object 1
    University micheal = {"tuks", 1900};
    speak(micheal);

    // object 2
    University matthew = {"su", 1899};
    speak(matthew);

    // object 3
    University boble = {"uct", 1910};
    speak(boble);

    // call it again !duplication
    speak(micheal);

    // Get year of establishment
    int x = getYear(micheal);
    printf("%d\n", x);

    // Change the year of establishment
    setYear(&micheal, 2400);
    speak(micheal);

    // boble.graduate();  Can't call this, it's private in Java and commented in C
    return 0;
}
