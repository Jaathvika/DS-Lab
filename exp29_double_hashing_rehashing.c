// Experiment 4: Tower of Hanoi

#include <stdio.h>

int moveCount = 0;

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        moveCount++;
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveCount++;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("=== Tower of Hanoi ===\n");
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\nSteps to solve Tower of Hanoi with %d disks:\n\n", n);
    hanoi(n, 'A', 'C', 'B');
    printf("\nTotal moves required: %d\n", moveCount);
    printf("Formula: 2^n - 1 = %d\n", (1 << n) - 1);
    return 0;
}
