#include <stdio.h>
#include<string.h>

void sorting(char a[][20], int n) {
    char temp [20];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(strcmp(a[j],a[j+1])>0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j+1]);
                strcpy(a[j+1], temp);
            }
        }
    }
}

int main() {
   char a[5][20];
   int n = 5;
   for(int i=0; i<n; i++) {
    scanf("%s", &a[i]);
   }
   sorting(a, n);
    for(int i=0; i<n; i++) {
    printf("%s ", a[i]);
   }
    return 0;
}
