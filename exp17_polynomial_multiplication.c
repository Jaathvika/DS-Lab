// Experiment 28: Implementation of Hashing by Quadratic Probing

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11  // Prime number recommended for quadratic probing
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = EMPTY;
}

int hashFunction(int key) { return key % TABLE_SIZE; }

void insert(int key) {
    int index = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Key %d inserted at index %d (probe %d)\n", key, newIndex, i);
            return;
        }
    }
    printf("Hash table is full! Cannot insert %d\n", key);
}

void search(int key) {
    int index = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY) { printf("Key %d not found\n", key); return; }
        if (hashTable[newIndex] == key) { printf("Key %d found at index %d\n", key, newIndex); return; }
    }
    printf("Key %d not found\n", key);
}

void deleteKey(int key) {
    int index = hashFunction(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i * i) % TABLE_SIZE;
        if (hashTable[newIndex] == EMPTY) { printf("Key %d not found\n", key); return; }
        if (hashTable[newIndex] == key) {
            hashTable[newIndex] = DELETED;
            printf("Key %d deleted from index %d\n", key, newIndex);
            return;
        }
    }
    printf("Key %d not found\n", key);
}

void display() {
    printf("\nHash Table (Quadratic Probing):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %2d: ", i);
        if (hashTable[i] == EMPTY) printf("EMPTY");
        else if (hashTable[i] == DELETED) printf("DELETED");
        else printf("%d", hashTable[i]);
        printf("\n");
    }
}

int main() {
    initTable();
    int choice, key;
    printf("=== Hashing by Quadratic Probing (Table Size=%d) ===\n", TABLE_SIZE);
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
