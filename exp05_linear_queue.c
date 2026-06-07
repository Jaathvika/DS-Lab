// Experiment 11: Implementation of Circular Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = NULL;
    return n;
}

void insertEnd(int data) {
    Node *n = createNode(data);
    if (!head) { head = n; n->next = head; }
    else {
        Node *t = head;
        while (t->next != head) t = t->next;
        t->next = n; n->next = head;
    }
    printf("%d inserted at end\n", data);
}

void insertBeginning(int data) {
    Node *n = createNode(data);
    if (!head) { head = n; n->next = head; }
    else {
        Node *t = head;
        while (t->next != head) t = t->next;
        n->next = head; t->next = n; head = n;
    }
    printf("%d inserted at beginning\n", data);
}

void deleteNode(int data) {
    if (!head) { printf("List is empty!\n"); return; }
    Node *curr = head, *prev = NULL;
    // Find node
    do {
        if (curr->data == data) break;
        prev = curr; curr = curr->next;
    } while (curr != head);

    if (curr->data != data) { printf("%d not found!\n", data); return; }

    if (curr == head && curr->next == head) {
        free(curr); head = NULL;
    } else if (curr == head) {
        Node *t = head;
        while (t->next != head) t = t->next;
        head = head->next; t->next = head;
        free(curr);
    } else {
        prev->next = curr->next;
        free(curr);
    }
    printf("%d deleted\n", data);
}

void display() {
    if (!head) { printf("List is empty!\n"); return; }
    printf("Circular List: ");
    Node *t = head;
    do { printf("%d -> ", t->data); t = t->next; } while (t != head);
    printf("(head)\n");
}

int main() {
    int choice, val;
    printf("=== Circular Linked List ===\n");
    do {
        printf("\n1. Insert End\n2. Insert Beginning\n3. Delete\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); insertEnd(val); break;
            case 2: printf("Value: "); scanf("%d", &val); insertBeginning(val); break;
            case 3: printf("Value to delete: "); scanf("%d", &val); deleteNode(val); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
