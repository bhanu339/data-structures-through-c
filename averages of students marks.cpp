#include <stdio.h>

struct Student {
    int rollno;
    float marks;
};

int main() {
    int n, i;
    float total = 0, average;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Input marks
    for(i = 0; i < n; i++) {
        printf("\nEnter roll number of student %d: ", i + 1);
        scanf("%d", &s[i].rollno);

        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &s[i].marks);

        total += s[i].marks;
    }

    // Calculate average
    average = total / n;

    // Output results
    printf("\n----- RESULT -----\n");
    printf("Total Marks = %.2f\n", total);
    printf("Average Marks = %.2f\n", average);

    return 0;
}
