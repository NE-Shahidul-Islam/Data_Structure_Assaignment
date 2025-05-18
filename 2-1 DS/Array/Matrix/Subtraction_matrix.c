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

    int subtraction[2][3];

    // Matrix subtraction
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            subtraction[i][j] = A[i][j] - B[i][j];
        }
    }

    // Print result
    printf("Difference of matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", subtraction[i][j]);
        }
        printf("\n");
    }

    return 0;
}
