// Experiment 8: Implementation of Single Linked List

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

void insertBeginning(int data) {
    Node *n = createNode(data);
    n->next = head; head = n;
    printf("%d inserted at beginning\n", data);
}

void insertEnd(int data) {
    Node *n = createNode(data);
    if (!head) { head = n; }
    else { Node *t = head; while (t->next) t = t->next; t->next = n; }
    printf("%d inserted at end\n", data);
}

void insertAt(int pos, int data) {
    if (pos == 1) { insertBeginning(data); return; }
    Node *t = head;
    for (int i = 1; i < pos - 1 && t; i++) t = t->next;
    if (!t) { printf("Position out of range\n"); return; }
    Node *n = createNode(data);
    n->next = t->next; t->next = n;
    printf("%d inserted at position %d\n", data, pos);
}

void deleteBeginning() {
    if (!head) { printf("List is empty!\n"); return; }
    Node *t = head; head = head->next;
    printf("%d deleted from beginning\n", t->data);
    free(t);
}

void deleteEnd() {
    if (!head) { printf("List is empty!\n"); return; }
    if (!head->next) { printf("%d deleted from end\n", head->data); free(head); head = NULL; return; }
    Node *t = head;
    while (t->next->next) t = t->next;
    printf("%d deleted from end\n", t->next->data);
    free(t->next); t->next = NULL;
}

void deleteNode(int data) {
    if (!head) { printf("List is empty!\n"); return; }
    if (head->data == data) { deleteBeginning(); return; }
    Node *t = head;
    while (t->next && t->next->data != data) t = t->next;
    if (!t->next) { printf("%d not found\n", data); return; }
    Node *del = t->next; t->next = del->next;
    printf("%d deleted\n", data);
    free(del);
}

void search(int data) {
    Node *t = head; int pos = 1;
    while (t) { if (t->data == data) { printf("%d found at position %d\n", data, pos); return; } t = t->next; pos++; }
    printf("%d not found\n", data);
}

void display() {
    if (!head) { printf("List is empty!\n"); return; }
    printf("List: ");
    Node *t = head;
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}

int main() {
    int choice, val, pos;
    printf("=== Single Linked List ===\n");
    do {
        printf("\n1. Insert Beginning\n2. Insert End\n3. Insert At Position\n");
        printf("4. Delete Beginning\n5. Delete End\n6. Delete By Value\n");
        printf("7. Search\n8. Display\n9. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); insertBeginning(val); break;
            case 2: printf("Value: "); scanf("%d", &val); insertEnd(val); break;
            case 3: printf("Position: "); scanf("%d", &pos); printf("Value: "); scanf("%d", &val); insertAt(pos, val); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Value to delete: "); scanf("%d", &val); deleteNode(val); break;
            case 7: printf("Value to search: "); scanf("%d", &val); search(val); break;
            case 8: display(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);
    return 0;
}
