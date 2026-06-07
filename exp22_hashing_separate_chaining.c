// Experiment 15: Merge of 2 Linked Lists (Sorted)

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

void insertSorted(Node **head, int data) {
    Node *n = createNode(data);
    if (!*head || (*head)->data >= data) { n->next = *head; *head = n; return; }
    Node *t = *head;
    while (t->next && t->next->data < data) t = t->next;
    n->next = t->next; t->next = n;
}

void display(Node *head, const char *name) {
    printf("%s: ", name);
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

Node* mergeSorted(Node *l1, Node *l2) {
    Node dummy = {0, NULL};
    Node *tail = &dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main() {
    Node *list1 = NULL, *list2 = NULL;
    int n, val;

    printf("=== Merge of Two Sorted Linked Lists ===\n");

    printf("Enter elements for List 1 (they will be sorted): ");
    printf("\nNumber of elements: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  Element %d: ", i + 1); scanf("%d", &val);
        insertSorted(&list1, val);
    }

    printf("Enter elements for List 2: ");
    printf("\nNumber of elements: "); scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("  Element %d: ", i + 1); scanf("%d", &val);
        insertSorted(&list2, val);
    }

    printf("\nBefore Merge:\n");
    display(list1, "List 1 (sorted)");
    display(list2, "List 2 (sorted)");

    Node *merged = mergeSorted(list1, list2);
    printf("\nMerged Sorted List:\n");
    display(merged, "Merged");

    return 0;
}
