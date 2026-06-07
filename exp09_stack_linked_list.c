// Experiment 23: Implementation of Hashing by Linear Probing

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int hashTable[TABLE_SIZE];

void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = EMPTY;
}

int hashFunction(int key) { return key % TABLE_SIZE; }

void insert(int key) {
    int index = hashFunction(key);
    int start = index;
    do {
        if (hashTable[index] == EMPTY || hashTable[index] == DELETED) {
            hashTable[index] = key;
            printf("Key %d inserted at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);
    printf("Hash table is full! Cannot insert %d\n", key);
}

void search(int key) {
    int index = hashFunction(key);
    int start = index;
    do {
        if (hashTable[index] == EMPTY) { printf("Key %d not found\n", key); return; }
        if (hashTable[index] == key) { printf("Key %d found at index %d\n", key, index); return; }
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);
    printf("Key %d not found\n", key);
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int start = index;
    do {
        if (hashTable[index] == EMPTY) { printf("Key %d not found\n", key); return; }
        if (hashTable[index] == key) {
            hashTable[index] = DELETED;
            printf("Key %d deleted from index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != start);
    printf("Key %d not found\n", key);
}

void display() {
    printf("\nHash Table (Linear Probing):\n");
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
    printf("=== Hashing by Linear Probing (Table Size=%d) ===\n", TABLE_SIZE);
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
