#include <stdio.h>
#include <string.h>

// typedef for structure
typedef struct {
    int id;
    char name[30];
    float marks;
} Student;

Student s[100];
int count = 0;

// Add student
void addStudent() {
    printf("Enter ID: ");
    scanf("%d", &s[count].id);

    printf("Enter Name: ");
    scanf("%s", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student added successfully!\n");
}

// Display students
void displayStudents() {
    if (count == 0) {
        printf("No records found\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Marks: %.2f\n",
               s[i].id, s[i].name, s[i].marks);
    }
}

// Search student
void searchStudent() {
    int id, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("Found: ID=%d Name=%s Marks=%.2f\n",
                   s[i].id, s[i].name, s[i].marks);
            found = 1;
        }
    }

    if (!found)
        printf("Student not found\n");
}

// Delete student
void deleteStudent() {
    int id, found = 0;

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            printf("Student deleted\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student not found\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STUDENT MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
