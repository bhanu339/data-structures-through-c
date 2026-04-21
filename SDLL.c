#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

void insert_begin() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insert_end() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}

void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* last = head->prev;
        struct Node* temp = head;

        head = head->next;
        last->next = head;
        head->prev = last;

        free(temp);
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* last = head->prev;

    if (last == head) {
        free(head);
        head = NULL;
    } else {
        struct Node* secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        free(last);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CDLL MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: delete_begin(); break;
            case 4: delete_end(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
