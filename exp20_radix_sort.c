// Experiment 12: Implementation of Double Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->prev = n->next = NULL;
    return n;
}

void insertBeginning(int data) {
    Node *n = createNode(data);
    if (!head) { head = n; }
    else { n->next = head; head->prev = n; head = n; }
    printf("%d inserted at beginning\n", data);
}

void insertEnd(int data) {
    Node *n = createNode(data);
    if (!head) { head = n; return; }
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n; n->prev = t;
    printf("%d inserted at end\n", data);
}

void deleteBeginning() {
    if (!head) { printf("List is empty!\n"); return; }
    Node *t = head; printf("%d deleted from beginning\n", t->data);
    head = head->next;
    if (head) head->prev = NULL;
    free(t);
}

void deleteEnd() {
    if (!head) { printf("List is empty!\n"); return; }
    if (!head->next) { printf("%d deleted from end\n", head->data); free(head); head = NULL; return; }
    Node *t = head;
    while (t->next) t = t->next;
    printf("%d deleted from end\n", t->data);
    t->prev->next = NULL; free(t);
}

void displayForward() {
    if (!head) { printf("List is empty!\n"); return; }
    printf("Forward: ");
    Node *t = head;
    while (t) { printf("%d <-> ", t->data); t = t->next; }
    printf("NULL\n");
}

void displayBackward() {
    if (!head) { printf("List is empty!\n"); return; }
    Node *t = head;
    while (t->next) t = t->next;
    printf("Backward: ");
    while (t) { printf("%d <-> ", t->data); t = t->prev; }
    printf("NULL\n");
}

int main() {
    int choice, val;
    printf("=== Double Linked List ===\n");
    do {
        printf("\n1. Insert Beginning\n2. Insert End\n3. Delete Beginning\n4. Delete End\n5. Display Forward\n6. Display Backward\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); insertBeginning(val); break;
            case 2: printf("Value: "); scanf("%d", &val); insertEnd(val); break;
            case 3: deleteBeginning(); break;
            case 4: deleteEnd(); break;
            case 5: displayForward(); break;
            case 6: displayBackward(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);
    return 0;
}
