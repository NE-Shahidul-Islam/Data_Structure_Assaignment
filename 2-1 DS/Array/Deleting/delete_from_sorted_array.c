#include<stdio.h>
void delete_at(int a[], int *n, int val) {
    int idx = 0;
    for(int i=0; i<*n; i++) {
        if(a[i]==val) {
            idx = i; break;
        }
    }
    for(int i=idx; i<*n; i++) {
        a[i]=a[i+1];
    }
    *n = *n - 1;
}
int main() {
    int a[5]={1, 2, 3, 4, 5};
    int n = 5;
    int val = 3;

    delete_at(a, &n, val);
    for (int i = 0; i < n; i++)
   {
    printf("%d ", a[i]);
   }
}