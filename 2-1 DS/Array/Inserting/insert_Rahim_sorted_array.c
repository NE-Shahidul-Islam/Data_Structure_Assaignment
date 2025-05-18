#include<stdio.h>
#include<string.h>
void insert_at(char a[][100], int *n, char* val) {
    int i = *n-1;
    while(i>=0 && strcmp(a[i], val)>0) {
        strcpy(a[i+1], a[i]);
        i--;
    }
    strcpy(a[i+1], val);
    *n = *n + 1;
}



int main(){
    char a[100][100]={"Habib", "Labib", "Mabib"};
    int maxi = 100;
    int n = 3;
    insert_at(a, &n,  "Karim");
    for(int i=0; i<n; i++) printf("%s ", a[i]);
    return 0;
}