/*Sparse Matrix: Store the element of a Triangular matrix A
 into a 1D array B and locate the elements A32 in
 the array B.
*/

#include <stdio.h>
#include<stdlib.h>

int main() {
    int n = 4;
    int A[4][4] = {
        {1, 0, 0, 0},
        {2, 3, 0, 0},
        {4, 5, 6, 0},
        {7, 8, 9, 10}
    };

    int size = n * (n + 1) / 2;
    int B[size];

    // Store lower triangular elements in 1D array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            B[k++] = A[i][j];
        }
    }

    // Find A[3][2]
    int i = 3, j = 2; // 0-based
    if (j <= i) {
        int index = i * (i + 1) / 2 + j;
        printf("A[3][2] = %d (stored at B[%d])\n", B[index], index);
    } else {
        printf("A[3][2] = 0 (outside lower triangle)\n");
    }

    return 0;
}
