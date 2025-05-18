#include <stdio.h>

int main() {
    char a[] = {'H', 'e', 'l', 'l', 'o'};
    char b[] = {' ', 'W', 'o', 'r', 'l', 'd'};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    char merged[n + m];

    // Copy elements of a
    for (int i = 0; i < n; i++) {
        merged[i] = a[i];
    }

    // Copy elements of b
    for (int i = 0; i < m; i++) {
        merged[n + i] = b[i];
    }

    // Print merged array as characters
    printf("Merged character array: ");
    for (int i = 0; i < n + m; i++) {
        printf("%c", merged[i]);
    }
    printf("\n");

    return 0;
}
