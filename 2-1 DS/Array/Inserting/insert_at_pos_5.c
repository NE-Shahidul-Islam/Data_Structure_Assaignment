#include<stdio.h>
int main(){
    int a[]={1, 2, 40, 50, 70, 90, 20, 3};
    int n = sizeof(a)/sizeof(int);

    //As 5 e bosaite hobe 
    //taile 5 theke sobaike pichone soraite hobe
    //0-Based indexing
    for(int i=n; i>=4; i--) {
        a[i]=a[i-1];
    }
    //0 based 
    a[4]=99;
    for(int i=0; i<=n; i++) printf("%d ", a[i]);
}