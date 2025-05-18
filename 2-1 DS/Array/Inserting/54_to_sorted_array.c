#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60}; 
    int n = 6; 
    int x = 54; 
    int i = n - 1;
    while (i >= 0 && arr[i] > x) {
        arr[i + 1] = arr[i]; 
        i--;
    }
    arr[i + 1] = x; 
    n++; 

    // Print 
    for (int j = 0; j < n; j++) {
        printf("%d ", arr[j]);
    }

    return 0;
}
