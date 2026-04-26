#include <stdio.h>

// Structure definition
struct Student {
    int roll;
    char name[20];
    float marks;
};

// Function to display structure (passed by value)
void display(struct Student s) {
    printf("\nInside Function (Copy of Structure):\n");
    printf("Roll No: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    // Modifying copy (will NOT affect original)
    s.marks = 100;
    printf("Modified Marks inside function: %.2f\n", s.marks);
}

int main() {
    struct Student s1;

    // Input data
    s1.roll = 101;
    printf("Enter name: ");
    scanf("%s", s1.name);
    s1.marks = 85.5;

    // Passing entire structure by value
    display(s1);

    // Original structure remains unchanged
    printf("\nBack in Main Function:\n");
    printf("Marks (original): %.2f\n", s1.marks);

    return 0;
}
