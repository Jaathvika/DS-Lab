// Experiment 2: Conversion of Infix to Postfix Expression (detailed)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return (top == -1) ? -1 : stack[top]; }
int isEmpty() { return top == -1; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char *exp) {
    char result[MAX];
    int k = 0;
    printf("\nStep-by-step conversion:\n");
    printf("%-15s %-20s %-20s\n", "Character", "Stack", "Output");
    printf("------------------------------------------------\n");

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (isalnum(c)) {
            result[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(')
                result[k++] = pop();
            if (!isEmpty()) pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c))
                result[k++] = pop();
            push(c);
        }
        // Print step
        char stackStr[MAX] = "", outStr[MAX] = "";
        for (int j = 0; j <= top; j++) { char t[2] = {stack[j], '\0'}; strcat(stackStr, t); }
        for (int j = 0; j < k; j++) { char t[2] = {result[j], '\0'}; strcat(outStr, t); }
        printf("%-15c %-20s %-20s\n", c, stackStr, outStr);
    }
    while (!isEmpty()) result[k++] = pop();
    result[k] = '\0';
    printf("\nPostfix Expression: %s\n", result);
}

int main() {
    char infix[MAX];
    printf("=== Infix to Postfix Conversion ===\n");
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
