// Experiment 7: Implementation of Deque (Double Ended Queue)

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

int isFull()  { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void insertFront(int val) {
    if (isFull()) { printf("Deque is Full!\n"); return; }
    if (front == -1) { front = rear = 0; }
    else front = (front - 1 + MAX) % MAX;
    deque[front] = val;
    printf("%d inserted at front\n", val);
}

void insertRear(int val) {
    if (isFull()) { printf("Deque is Full!\n"); return; }
    if (front == -1) { front = rear = 0; }
    else rear = (rear + 1) % MAX;
    deque[rear] = val;
    printf("%d inserted at rear\n", val);
}

int deleteFront() {
    if (isEmpty()) { printf("Deque is Empty!\n"); return -1; }
    int val = deque[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
    return val;
}

int deleteRear() {
    if (isEmpty()) { printf("Deque is Empty!\n"); return -1; }
    int val = deque[rear];
    if (front == rear) front = rear = -1;
    else rear = (rear - 1 + MAX) % MAX;
    return val;
}

void display() {
    if (isEmpty()) { printf("Deque is Empty!\n"); return; }
    printf("Deque (front to rear): ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;
    printf("=== Deque Implementation ===\n");
    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); insertFront(val); break;
            case 2: printf("Value: "); scanf("%d", &val); insertRear(val); break;
            case 3: val = deleteFront(); if (val != -1) printf("Deleted from front: %d\n", val); break;
            case 4: val = deleteRear(); if (val != -1) printf("Deleted from rear: %d\n", val); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}
