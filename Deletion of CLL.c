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

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Delete from beginning
void deleteFromBeginning() {
    struct Node *temp = head, *last;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if(head->next == head) {
        printf("%d deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Find last node
    last = head;
    while(last->next != head) {
        last = last->next;
    }

    temp = head;
    head = head->next;
    last->next = head;

    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    struct Node *temp = head, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Only one node
    if(head->next == head) {
        printf("%d deleted\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

    printf("%d deleted from end\n", temp->data);
    free(temp);
}

// Delete from position
void deleteFromPosition(int pos) {
    struct Node *temp = head, *prev;

    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    // First node
    if(pos == 1) {
        deleteFromBeginning();
        return;
    }

    for(int i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == head) {
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

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != head);

    printf("(back to head)\n");
}

int main() {
    int choice, value, pos;

    while(1) {
        printf("\n--- CIRCULAR LINKED LIST DELETION ---\n");
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
