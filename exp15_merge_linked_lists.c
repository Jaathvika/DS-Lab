// Experiment 24: Implementation of Binary Search Tree (BST)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

Node* insert(Node *root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    else printf("Duplicate value %d not inserted\n", data);
    return root;
}

Node* search(Node *root, int data) {
    if (!root || root->data == data) return root;
    if (data < root->data) return search(root->left, data);
    return search(root->right, data);
}

Node* minNode(Node *node) {
    while (node->left) node = node->left;
    return node;
}

Node* deleteNode(Node *root, int data) {
    if (!root) return root;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {
        if (!root->left) { Node *t = root->right; free(root); return t; }
        if (!root->right) { Node *t = root->left; free(root); return t; }
        Node *temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)   { if (root) { inorder(root->left); printf("%d ", root->data); inorder(root->right); } }
void preorder(Node *root)  { if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); } }
void postorder(Node *root) { if (root) { postorder(root->left); postorder(root->right); printf("%d ", root->data); } }

int main() {
    Node *root = NULL;
    int choice, val;
    printf("=== Binary Search Tree (BST) ===\n");
    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder\n5. Preorder\n6. Postorder\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2:
                printf("Value to search: "); scanf("%d", &val);
                if (search(root, val)) printf("%d found in BST\n", val);
                else printf("%d not found\n", val);
                break;
            case 3: printf("Value to delete: "); scanf("%d", &val); root = deleteNode(root, val); printf("%d deleted\n", val); break;
            case 4: printf("Inorder (sorted): "); inorder(root); printf("\n"); break;
            case 5: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 6: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);
    return 0;
}
