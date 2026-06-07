// Experiment 1: Implementation of Stack using Array
// Conversion of Infix to Postfix Expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) { printf("Stack Overflow\n"); return; }
    stack[++top] = c;
}

char pop() {
    if (top == -1) { printf("Stack Underflow\n"); return -1; }
    return stack[top--];
}

char peek() {
    if (top == -1) return -1;
    return stack[top];
}

int isEmpty() { return top == -1; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char c;
    while ((c = infix[i++]) != '\0') {
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            if (!isEmpty()) pop(); // remove '('
        } else if (isOperator(c)) {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (!isEmpty()) postfix[j++] = pop();
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("=== Stack using Array: Infix to Postfix ===\n");
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
