#include <stdio.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};

int main() {
    struct Student s1, s2;

    // Input for first student
    printf("Enter roll number: ");
    scanf("%d", &s1.rollno);

    printf("Enter name: ");
    scanf(" %[^\n]", s1.name);

    printf("Enter marks: ");
    scanf("%f", &s1.marks);

    // Copy structure variable
    s2 = s1;

    // Display copied data
    printf("\n--- Copied Structure Data ---\n");
    printf("Roll Number: %d\n", s2.rollno);
    printf("Name: %s\n", s2.name);
    printf("Marks: %.2f\n", s2.marks);

    return 0;
}
