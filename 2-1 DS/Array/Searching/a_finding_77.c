#include <stdio.h>

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i; // return index if found
    }
    return -1; // not found
}

int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid; // found
        else if (arr[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; // not found
}

int main() {
    int a[] = {5, 6, 7, 9, 11, 77};
    int b[] = {1, 2, 3, 30, 78, 98};  // Sorted array for binary search
    int n = sizeof(a) / sizeof(int);
    int x = 77;

    int idx1 = linearSearch(a, n, x);
    if (idx1 != -1)
        printf("%d is found using linear search at index %d.\n", x, idx1);
    else
        printf("%d is not found using linear search.\n", x);

    int idx2 = binarySearch(b, n, x);
    if (idx2 != -1)
        printf("%d is found using binary search at index %d.\n", x, idx2);
    else
        printf("%d is not found using binary search.\n", x);

    return 0;
}
