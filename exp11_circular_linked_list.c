// Experiment 20: Implementation of Radix Sort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("=== Radix Sort ===\n");
    printf("Enter number of elements: "); scanf("%d", &n);
    int arr[n];
    printf("Enter elements (non-negative integers): ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("\nBefore sorting: "); display(arr, n);
    radixSort(arr, n);
    printf("After sorting:  "); display(arr, n);

    return 0;
}
