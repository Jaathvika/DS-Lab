// Experiment 31: Implementation of Priority Queue using Ordered List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

Node *head = NULL;

Node* createNode(int data, int priority) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->priority = priority; n->next = NULL;
    return n;
}

// Insert in sorted order by priority (lower number = higher priority)
void enqueue(int data, int priority) {
    Node *n = createNode(data, priority);
    if (!head || priority < head->priority) {
        n->next = head; head = n;
    } else {
        Node *t = head;
        while (t->next && t->next->priority <= priority) t = t->next;
        n->next = t->next; t->next = n;
    }
    printf("(%d, priority=%d) inserted\n", data, priority);
}

int dequeue() {
    if (!head) { printf("Priority Queue is Empty!\n"); return -1; }
    Node *t = head; int val = t->data;
    printf("Dequeued: %d (priority=%d)\n", t->data, t->priority);
    head = head->next; free(t);
    return val;
}

void display() {
    if (!head) { printf("Priority Queue is Empty!\n"); return; }
    printf("Priority Queue (front to rear):\n");
    Node *t = head;
    while (t) { printf("  [Data=%d, Priority=%d]\n", t->data, t->priority); t = t->next; }
}

int main() {
    int choice, val, pri;
    printf("=== Priority Queue using Ordered List ===\n");
    printf("(Lower priority number = higher priority)\n");
    do {
        printf("\n1. Enqueue\n2. Dequeue (highest priority)\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Data: "); scanf("%d", &val);
                printf("Priority: "); scanf("%d", &pri);
                enqueue(val, pri); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
