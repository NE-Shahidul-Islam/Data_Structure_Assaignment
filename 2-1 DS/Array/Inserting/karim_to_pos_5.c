#include <stdio.h>
#include <string.h>

int main() {
    char a[10][20] = {"naruto", "hinata", "aizen", "kabuto", "levi", "mikasa"};
    int n = 6; 

    // Make space at index 4 for new entry by shifting elements
    for (int i = n; i > 4; i--) {
        strcpy(a[i], a[i - 1]);
    }

    // Insert "Karim" at index 4
    strcpy(a[4], "Karim");
    n++;
    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}
