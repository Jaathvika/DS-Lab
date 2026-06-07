// Experiment 9: Implementation of Stack using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = top; top = n;
    printf("%d pushed onto stack\n", data);
}

int pop() {
    if (!top) { printf("Stack Underflow!\n"); return -1; }
    Node *t = top; int val = t->data;
    top = top->next; free(t);
    return val;
}

int peek() {
    if (!top) { printf("Stack is Empty!\n"); return -1; }
    return top->data;
}

void display() {
    if (!top) { printf("Stack is Empty!\n"); return; }
    printf("Stack (top to bottom): ");
    Node *t = top;
    while (t) { printf("%d ", t->data); t = t->next; }
    printf("\n");
}

int main() {
    int choice, val;
    printf("=== Stack using Linked List ===\n");
    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); push(val); break;
            case 2: val = pop(); if (val != -1) printf("Popped: %d\n", val); break;
            case 3: val = peek(); if (val != -1) printf("Top element: %d\n", val); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
