// Experiment 25: Implementation of BST using Stack (Non-recursive traversals)

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Stack for tree nodes
typedef struct Stack {
    Node *data[100];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
void pushStack(Stack *s, Node *n) { s->data[++s->top] = n; }
Node* popStack(Stack *s) { return s->data[s->top--]; }
Node* peekStack(Stack *s) { return s->data[s->top]; }
int isEmptyStack(Stack *s) { return s->top == -1; }

Node* createNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = data; n->left = n->right = NULL;
    return n;
}

Node* insert(Node *root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

// Non-recursive inorder using stack
void inorderIterative(Node *root) {
    Stack s; initStack(&s);
    Node *curr = root;
    printf("Inorder (non-recursive): ");
    while (curr || !isEmptyStack(&s)) {
        while (curr) { pushStack(&s, curr); curr = curr->left; }
        curr = popStack(&s);
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

// Non-recursive preorder using stack
void preorderIterative(Node *root) {
    if (!root) return;
    Stack s; initStack(&s);
    pushStack(&s, root);
    printf("Preorder (non-recursive): ");
    while (!isEmptyStack(&s)) {
        Node *node = popStack(&s);
        printf("%d ", node->data);
        if (node->right) pushStack(&s, node->right);
        if (node->left)  pushStack(&s, node->left);
    }
    printf("\n");
}

// Non-recursive postorder using 2 stacks
void postorderIterative(Node *root) {
    if (!root) return;
    Stack s1, s2; initStack(&s1); initStack(&s2);
    pushStack(&s1, root);
    while (!isEmptyStack(&s1)) {
        Node *node = popStack(&s1);
        pushStack(&s2, node);
        if (node->left)  pushStack(&s1, node->left);
        if (node->right) pushStack(&s1, node->right);
    }
    printf("Postorder (non-recursive): ");
    while (!isEmptyStack(&s2)) printf("%d ", popStack(&s2)->data);
    printf("\n");
}

int main() {
    Node *root = NULL;
    int choice, val;
    printf("=== BST using Stack (Non-recursive traversals) ===\n");
    do {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2: inorderIterative(root); break;
            case 3: preorderIterative(root); break;
            case 4: postorderIterative(root); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
