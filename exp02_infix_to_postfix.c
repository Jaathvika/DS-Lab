// Experiment 3: Evaluation of Postfix Expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

double stack[MAX];
int top = -1;

void push(double val) {
    if (top == MAX - 1) { printf("Stack Overflow\n"); return; }
    stack[++top] = val;
}

double pop() {
    if (top == -1) { printf("Stack Underflow\n"); return 0; }
    return stack[top--];
}

double evaluatePostfix(char *exp) {
    double op1, op2, result;
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            push(c - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (c) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/':
                    if (op2 == 0) { printf("Division by zero!\n"); return 0; }
                    push(op1 / op2); break;
                case '^': push(pow(op1, op2)); break;
                default:  printf("Invalid operator: %c\n", c); return 0;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    printf("=== Postfix Expression Evaluation ===\n");
    printf("Enter postfix expression (single digit operands): ");
    scanf("%s", postfix);
    double result = evaluatePostfix(postfix);
    printf("Result = %.2f\n", result);
    return 0;
}
