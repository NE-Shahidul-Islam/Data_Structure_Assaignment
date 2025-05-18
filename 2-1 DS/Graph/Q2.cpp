#include <iostream>
using namespace std;

const int MAX = 100;

void multiply(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int m) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < m; ++k)
                result[i][j] += A[i][k] * B[k][j];
        }
}

void copy(int from[MAX][MAX], int to[MAX][MAX], int m) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            to[i][j] = from[i][j];
}

int main() {
    int m, A[MAX][MAX], power[MAX][MAX], temp[MAX][MAX], Br[MAX][MAX] = {0}, path[MAX][MAX];

    cin >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];

    copy(A, power, m);

    for (int p = 1; p <= m; ++p) {
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < m; ++j)
                Br[i][j] += power[i][j];
            }

        multiply(power, A, temp, m);
        copy(temp, power, m);
    }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < m; ++j){
            if(Br[i][j]) path[i][j]=1;
            else path[i][j]=0;
        }
     }

    bool stronglyConnected = true;
    for (int i = 0; i < m && stronglyConnected; ++i)
        for (int j = 0; j < m && stronglyConnected; ++j)
            if (path[i][j] == 0)
                stronglyConnected = false;

    cout << "Path Matrix:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j)
            cout << path[i][j] << " ";
        cout << "\n";
    }

    cout << (stronglyConnected ? "Strongly Connected\n" : "Not Strongly Connected\n");
    return 0;
}
