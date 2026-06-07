// Experiment 29: Implementation of Double Hashing with Rehashing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 7
#define EMPTY -1
#define DELETED -2

int *hashTable;
int tableSize;
int count;

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

int nextPrime(int n) {
    while (!isPrime(n)) n++;
    return n;
}

void initTable(int size) {
    tableSize = size;
    hashTable = (int*)malloc(tableSize * sizeof(int));
    for (int i = 0; i < tableSize; i++) hashTable[i] = EMPTY;
    count = 0;
}

int h1(int key) { return key % tableSize; }
int h2(int key) { return 1 + (key % (tableSize - 1)); }

void insertKey(int key);

void rehash() {
    printf("\n--- Rehashing triggered! Table size: %d -> ", tableSize);
    int *oldTable = hashTable;
    int oldSize = tableSize;

    tableSize = nextPrime(2 * oldSize);
    printf("%d ---\n", tableSize);

    hashTable = (int*)malloc(tableSize * sizeof(int));
    for (int i = 0; i < tableSize; i++) hashTable[i] = EMPTY;
    count = 0;

    for (int i = 0; i < oldSize; i++)
        if (oldTable[i] != EMPTY && oldTable[i] != DELETED)
            insertKey(oldTable[i]);

    free(oldTable);
}

void insertKey(int key) {
    if ((float)count / tableSize >= 0.7) rehash();

    int index = h1(key);
    int step = h2(key);
    for (int i = 0; i < tableSize; i++) {
        int newIndex = (index + i * step) % tableSize;
        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            count++;
            printf("Key %d inserted at index %d\n", key, newIndex);
            return;
        }
    }
    printf("Table full! Cannot insert %d\n", key);
}

void search(int key) {
    int index = h1(key);
    int step = h2(key);
    for (int i = 0; i < tableSize; i++) {
        int newIndex = (index + i * step) % tableSize;
        if (hashTable[newIndex] == EMPTY) { printf("Key %d not found\n", key); return; }
        if (hashTable[newIndex] == key) { printf("Key %d found at index %d\n", key, newIndex); return; }
    }
    printf("Key %d not found\n", key);
}

void display() {
    printf("\nHash Table (Double Hashing, size=%d):\n", tableSize);
    for (int i = 0; i < tableSize; i++) {
        printf("Index %2d: ", i);
        if (hashTable[i] == EMPTY) printf("EMPTY");
        else if (hashTable[i] == DELETED) printf("DELETED");
        else printf("%d", hashTable[i]);
        printf("\n");
    }
    printf("Load factor: %.2f\n", (float)count / tableSize);
}

int main() {
    initTable(INITIAL_SIZE);
    int choice, key;
    printf("=== Double Hashing with Rehashing (Initial Size=%d) ===\n", INITIAL_SIZE);
    do {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Key: "); scanf("%d", &key); insertKey(key); break;
            case 2: printf("Key: "); scanf("%d", &key); search(key); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
    free(hashTable);
    return 0;
}
