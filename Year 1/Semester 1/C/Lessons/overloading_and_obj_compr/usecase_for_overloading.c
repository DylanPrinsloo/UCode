#include <stdio.h>
#include <string.h>

// Define the Student struct
typedef struct {
    char name[50];
} Student;

// Constructor function for Student
Student createStudent(const char *name) {
    Student s;
    strcpy(s.name, name);
    return s;
}

// Equality check function (equivalent to `equals` method in Java)
int isEqual(Student s1, Student s2) {
    return strcmp(s1.name, s2.name) == 0;
}

// Comparison function (equivalent to `compareTo` method in Java)
int compareTo(Student s1, Student s2) {
    return strcmp(s1.name, s2.name);
}

int main() {
    // Creating three Student objects
    Student joe = createStudent("Joe");
    Student mike = createStudent("Joe");  // Note: Same name as joe
    Student dylan = createStudent("Dylan");

    // Pointer comparison (equivalent to '==' in Java)
    printf("joe == mike: %d\n", &joe == &mike);  // This will print: 0 (false)

    // Equality check using isEqual (equivalent to 'equals' method in Java)
    printf("joe.equals(mike): %d\n", isEqual(joe, mike));  // This will print: 1 (true)

    // Compare using compareTo (equivalent to 'compareTo' method in Java)
    printf("joe.compareTo(mike): %d\n", compareTo(joe, mike));  // This will print: 0 (names are equal)

    printf("joe.compareTo(dylan): %d\n", compareTo(joe, dylan));  // Prints comparison result based on lexicographical order

    // Boolean comparison using compareTo
    printf("joe.compareTo(mike) > 0: %d\n", compareTo(joe, mike) > 0);  // This will print: 0 (false, since the names are equal)

    return 0;
}


