#include <stdio.h>

int main() {
    int rows = 2, cols = 3;

    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int B[2][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };

    int sum[2][3];

    // Matrix addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Print result
    printf("Sum of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
