// Experiment 10: Implementation of Queue using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = NULL;
    if (!rear) { front = rear = n; }
    else { rear->next = n; rear = n; }
    printf("%d enqueued\n", data);
}

int dequeue() {
    if (!front) { printf("Queue is Empty!\n"); return -1; }
    Node *t = front; int val = t->data;
    front = front->next;
    if (!front) rear = NULL;
    free(t);
    return val;
}

void display() {
    if (!front) { printf("Queue is Empty!\n"); return; }
    printf("Queue (front to rear): ");
    Node *t = front;
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}

int main() {
    int choice, val;
    printf("=== Queue using Linked List ===\n");
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); enqueue(val); break;
            case 2: val = dequeue(); if (val != -1) printf("Dequeued: %d\n", val); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
