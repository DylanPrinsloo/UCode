#include <stdio.h>
#include <string.h>

// Base struct (equivalent to Java's 'university' class)
typedef struct {
    char name[50];
    int year;
} University;

// Derived struct (equivalent to the 'inheritance' class extending 'university')
typedef struct {
    University base;
    int ranking;
} Inheritance;

// Constructor for Inheritance struct with ranking
Inheritance newInheritanceWithRanking(int year, const char *name, int ranking) {
    Inheritance i;
    strcpy(i.base.name, name);
    i.base.year = year;
    i.ranking = ranking;
    return i;
}

// Constructor for Inheritance struct with default ranking
Inheritance newInheritanceWithDefaultRanking(const char *name, int year) {
    Inheritance i;
    strcpy(i.base.name, name);
    i.base.year = year;
    i.ranking = 50; // default ranking
    return i;
}

// Method to modify the ranking
void adjustRanking(Inheritance *i, int x) {
    i->ranking -= x;
}

// Getter for ranking
int getRanking(Inheritance i) {
    return i.ranking;
}

// Setter for ranking
void setRanking(Inheritance *i, int ranking) {
    i->ranking = ranking;
}

// Protected method to modify the university name
void setUniversityName(Inheritance *i, const char *name) {
    strcpy(i->base.name, name);
}

int main() {
    // Create an object with specified ranking
    Inheritance uni1 = newInheritanceWithRanking(1900, "tuks", 10);
    printf("University: %s, Year: %d, Ranking: %d\n", uni1.base.name, uni1.base.year, uni1.ranking);

    // Create an object with default ranking
    Inheritance uni2 = newInheritanceWithDefaultRanking("su", 1899);
    printf("University: %s, Year: %d, Ranking: %d\n", uni2.base.name, uni2.base.year, uni2.ranking);

    // Modify ranking and print again
    adjustRanking(&uni1, 5);
    printf("Modified Ranking: %d\n", getRanking(uni1));

    // Modify university name
    setUniversityName(&uni2, "uct");
    printf("Updated University: %s\n", uni2.base.name);

    return 0;
}

