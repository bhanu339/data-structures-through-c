#include <stdio.h>

struct Student {
    int roll;
    char name[20];
    float marks;
};

int main() {
    struct Student s1;

    // Assign values to individual structure elements
    s1.roll = 101;
    s1.marks = 89.5;

    printf("Enter name: ");
    scanf("%s", s1.name);

    // Accessing individual elements
    printf("\nStudent Details:\n");
    printf("Roll No: %d\n", s1.roll);
    printf("Name: %s\n", s1.name);
    printf("Marks: %.2f\n", s1.marks);

    return 0;
}
