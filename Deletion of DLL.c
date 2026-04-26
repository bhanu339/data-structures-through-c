#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at end (for testing)
void insert(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = head;

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete from beginning
void deleteFromBeginning() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if(head != NULL) {
        head->prev = NULL;
    }

    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    struct Node *temp;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if(temp->next == NULL) {
        printf("%d deleted from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    printf("%d deleted from end\n", temp->data);
    free(temp);
}

// Delete from specific position
void deleteFromPosition(int pos) {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(pos == 1) {
        head = temp->next;

        if(head != NULL) {
            head->prev = NULL;
        }

        printf("%d deleted from position %d\n", temp->data, pos);
        free(temp);
        return;
    }

    for(int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    printf("%d deleted from position %d\n", temp->data, pos);
    free(temp);
}

// Display list
void display() {
    struct Node *temp = head;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while(1) {
        printf("\n--- DOUBLY LINKED LIST DELETION ---\n");
        printf("1. Insert (for testing)\n");
        printf("2. Delete from Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete from Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteFromBeginning();
                break;

            case 3:
                deleteFromEnd();
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
