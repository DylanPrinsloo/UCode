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

// Getter for the name field
const char* getName(Student s) {
    return s.name;
}

// Setter for the name field
void setName(Student *s, const char *name) {
    strcpy(s->name, name);
}

// ToString equivalent function for displaying the student
void toString(Student s) {
    printf("Student(%s)\n", s.name);
}

int main() {
    // Creating two Student objects
    Student student1 = createStudent("Alice");
    Student student2 = createStudent("Bob");

    // Displaying the students
    toString(student1);
    toString(student2);

    // Comparing students
    if (isEqual(student1, student2)) {
        printf("The students are equal.\n");
    } else {
        printf("The students are not equal.\n");
    }

    // Using the comparison function
    int comparison = compareTo(student1, student2);
    if (comparison < 0) {
        printf("%s comes before %s alphabetically.\n", student1.name, student2.name);
    } else if (comparison > 0) {
        printf("%s comes after %s alphabetically.\n", student1.name, student2.name);
    } else {
        printf("The students have the same name.\n");
    }

    return 0;
}


