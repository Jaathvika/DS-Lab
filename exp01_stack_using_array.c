// Experiment 14: Reverse of 2 Linked Lists

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->next = NULL;
    return n;
}

void append(Node **head, int data) {
    Node *n = createNode(data);
    if (!*head) { *head = n; return; }
    Node *t = *head;
    while (t->next) t = t->next;
    t->next = n;
}

void display(Node *head, const char *name) {
    printf("%s: ", name);
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

Node* reverse(Node *head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node *list1 = NULL, *list2 = NULL;
    int n, val;

    printf("=== Reverse of Two Linked Lists ===\n");

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  Element %d: ", i + 1); scanf("%d", &val);
        append(&list1, val);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  Element %d: ", i + 1); scanf("%d", &val);
        append(&list2, val);
    }

    printf("\nOriginal:\n");
    display(list1, "List 1");
    display(list2, "List 2");

    list1 = reverse(list1);
    list2 = reverse(list2);

    printf("\nAfter Reversal:\n");
    display(list1, "List 1 Reversed");
    display(list2, "List 2 Reversed");

    return 0;
}
