#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("%d inserted at end\n", value);
}

// Insert at specific position
void insertAtPosition(int value, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("%d inserted at position %d\n", value, pos);
        return;
    }

    for(int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted at position %d\n", value, pos);
}

// Display list
void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while(1) {
        printf("\n--- LINKED LIST INSERTION ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
