#include <stdio.h>

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    int merged[n + m];

    // Copy elements of a
    for (int i = 0; i < n; i++) {
        merged[i] = a[i];
    }

    // Copy elements of b
    for (int i = 0; i < m; i++) {
        merged[n + i] = b[i];
    }

    // Print merged array
    printf("Merged integer array: ");
    for (int i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
