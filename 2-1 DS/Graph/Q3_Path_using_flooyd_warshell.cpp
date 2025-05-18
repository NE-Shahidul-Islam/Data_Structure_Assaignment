#include <iostream>
using namespace std;

const int MAX = 100;

int main() {
    int m, A[MAX][MAX];

    cin >> m;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];

    for (int k = 0; k < m; ++k)
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                A[i][j] = A[i][j] or (A[i][k] and A[k][j]);

    cout << "Path Matrix:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
