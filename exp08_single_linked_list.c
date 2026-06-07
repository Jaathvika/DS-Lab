// Experiment 33: Implementation of Priority Queue using Heap (Min-Heap)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int priority;
} Element;

Element heap[MAX];
int heapSize = 0;

void swap(Element *a, Element *b) { Element t = *a; *a = *b; *b = t; }

// Heapify up (after insertion)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].priority > heap[index].priority) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify down (after deletion)
void heapifyDown(int index) {
    int left, right, smallest;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < heapSize && heap[left].priority < heap[smallest].priority)
            smallest = left;
        if (right < heapSize && heap[right].priority < heap[smallest].priority)
            smallest = right;

        if (smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        } else break;
    }
}

void enqueue(int data, int priority) {
    if (heapSize == MAX) { printf("Priority Queue is Full!\n"); return; }
    heap[heapSize].data = data;
    heap[heapSize].priority = priority;
    heapifyUp(heapSize);
    heapSize++;
    printf("(%d, priority=%d) inserted\n", data, priority);
}

void dequeue() {
    if (heapSize == 0) { printf("Priority Queue is Empty!\n"); return; }
    printf("Dequeued: %d (priority=%d)\n", heap[0].data, heap[0].priority);
    heap[0] = heap[--heapSize];
    heapifyDown(0);
}

void peek() {
    if (heapSize == 0) { printf("Priority Queue is Empty!\n"); return; }
    printf("Highest priority element: %d (priority=%d)\n", heap[0].data, heap[0].priority);
}

void display() {
    if (heapSize == 0) { printf("Priority Queue is Empty!\n"); return; }
    printf("Priority Queue (heap representation):\n");
    for (int i = 0; i < heapSize; i++)
        printf("  [Data=%d, Priority=%d]\n", heap[i].data, heap[i].priority);
}

int main() {
    int choice, val, pri;
    printf("=== Priority Queue using Heap (Min-Heap) ===\n");
    printf("(Lower priority number = higher priority)\n");
    do {
        printf("\n1. Enqueue\n2. Dequeue (highest priority)\n3. Peek\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Data: "); scanf("%d", &val);
                printf("Priority: "); scanf("%d", &pri);
                enqueue(val, pri); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
