#include <iostream>
using namespace std;

#define MAX 100

int m;
int A[MAX][MAX], A2[MAX][MAX], A3[MAX][MAX], A4[MAX][MAX];

void multiplyMatrix(int result[MAX][MAX], int mat1[MAX][MAX], int mat2[MAX][MAX]) {
    int temp[MAX][MAX] = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < m; k++) {
                temp[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Copy result back
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            result[i][j] = temp[i][j];
}

void printMatrix(const string& label, int mat[MAX][MAX]) {
    cout << label << ":\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> m;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    // (a) Adjacents of each vertex
    for (int i = 0; i < m; i++) {
        cout << "Adjacent of V" << i << ": ";
        for (int j = 0; j < m; j++) {
            if (A[i][j] > 0) {
                cout << "V" << j << " ";
            }
        }
        cout << "\n";
    }

    // (b) A^2: Paths of length 2
    multiplyMatrix(A2, A, A);
    printMatrix("Number of paths of length 2 (A^2)", A2);

    // (c) A^3: Paths of length 3
    multiplyMatrix(A3, A2, A);
    printMatrix("Number of paths of length 3 (A^3)", A3);

    // (d) A^4: Paths of length 4
    multiplyMatrix(A4, A3, A);
    printMatrix("Number of paths of length 4 (A^4)", A4);

    return 0;
}
