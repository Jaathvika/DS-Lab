// Experiment 22: Implementation of Hashing by Separate Chaining

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = NULL;
}

int hashFunction(int key) { return key % TABLE_SIZE; }

void insert(int key) {
    int index = hashFunction(key);
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = key; n->next = hashTable[index];
    hashTable[index] = n;
    printf("Key %d inserted at index %d\n", key, index);
}

void search(int key) {
    int index = hashFunction(key);
    Node *t = hashTable[index];
    while (t) {
        if (t->data == key) { printf("Key %d found at index %d\n", key, index); return; }
        t = t->next;
    }
    printf("Key %d not found\n", key);
}

void deleteKey(int key) {
    int index = hashFunction(key);
    Node *curr = hashTable[index], *prev = NULL;
    while (curr) {
        if (curr->data == key) {
            if (prev) prev->next = curr->next;
            else hashTable[index] = curr->next;
            free(curr);
            printf("Key %d deleted from index %d\n", key, index);
            return;
        }
        prev = curr; curr = curr->next;
    }
    printf("Key %d not found\n", key);
}

void display() {
    printf("\nHash Table (Separate Chaining):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %2d: ", i);
        Node *t = hashTable[i];
        while (t) { printf("%d -> ", t->data); t = t->next; }
        printf("NULL\n");
    }
}

int main() {
    initTable();
    int choice, key;
    printf("=== Hashing by Separate Chaining (Table Size=%d) ===\n", TABLE_SIZE);
    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Key: "); scanf("%d", &key); insert(key); break;
            case 2: printf("Key: "); scanf("%d", &key); search(key); break;
            case 3: printf("Key: "); scanf("%d", &key); deleteKey(key); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
