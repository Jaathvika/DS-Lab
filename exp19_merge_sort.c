// Experiment 5: Implementation of Linear Queue

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

int isFull()  { return rear == MAX - 1; }
int isEmpty() { return front == -1 || front > rear; }

void enqueue(int val) {
    if (isFull()) { printf("Queue is Full!\n"); return; }
    if (front == -1) front = 0;
    queue[++rear] = val;
    printf("%d enqueued to queue\n", val);
}

int dequeue() {
    if (isEmpty()) { printf("Queue is Empty!\n"); return -1; }
    int val = queue[front++];
    if (front > rear) front = rear = -1;
    return val;
}

void display() {
    if (isEmpty()) { printf("Queue is Empty!\n"); return; }
    printf("Queue (front to rear): ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, val;
    printf("=== Linear Queue Implementation ===\n");
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
