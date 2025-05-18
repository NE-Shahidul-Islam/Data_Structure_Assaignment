#include <stdio.h>
#include <string.h>

int linearSearch(char a[][20], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i], key) == 0) {
            return i;  // found at index i
        }
    }
    return -1;  // not found
}

int binarySearch(char a[][20], int n, char key[]) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strcmp(a[mid], key);
        if (cmp == 0) return mid;
        else if (cmp > 0) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main() {
    // Sorted array of strings
    char a[][20] = {"aizen", "kabuto", "karim", "levi", "mikasa", "naruto"};
    int n = sizeof(a) / sizeof(a[0]);
    char key[] = "karim";

    int idx_linear = linearSearch(a, n, key);
    int idx_binary = binarySearch(a, n, key);

    if (idx_linear != -1) {
        printf("Linear Search: %s found at index %d\n", key, idx_linear);
    } else {
        printf("Linear Search: %s not found\n", key);
    }

    if (idx_binary != -1) {
        printf("Binary Search: %s found at index %d\n", key, idx_binary);
    } else {
        printf("Binary Search: %s not found\n", key);
    }

    return 0;
}
