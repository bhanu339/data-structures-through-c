#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
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
        head = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
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
    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    struct Node *temp, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL) {
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("%d deleted from end\n", temp->data);
    free(temp);
}

// Delete from specific position
void deleteFromPosition(int pos) {
    struct Node *temp = head, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    if(pos == 1) {
        head = temp->next;
        printf("%d deleted from position %d\n", temp->data, pos);
        free(temp);
        return;
    }

    for(int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
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
        printf("\n--- LINKED LIST DELETION ---\n");
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
