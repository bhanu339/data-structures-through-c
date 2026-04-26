#include <stdio.h>

// Inner structure
struct Date {
    int day;
    int month;
    int year;
};

// Outer structure
struct Student {
    int roll;
    char name[20];
    struct Date dob;   // Nested structure
};

int main() {
    struct Student s1;

    // Input data
    s1.roll = 101;
    printf("Enter name: ");
    scanf("%s", s1.name);

    printf("Enter DOB (day month year): ");
    scanf("%d %d %d", &s1.dob.day, &s1.dob.month, &s1.dob.year);

    // Display data
    printf("\nStudent Details:\n");
    printf("Roll No: %d\n", s1.roll);
    printf("Name: %s\n", s1.name);
    printf("DOB: %d-%d-%d\n", s1.dob.day, s1.dob.month, s1.dob.year);

    return 0;
}
