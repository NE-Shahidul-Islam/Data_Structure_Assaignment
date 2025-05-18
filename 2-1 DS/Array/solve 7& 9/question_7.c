/*Copy elements of a 2D array into a 1D/linear array 
and print the elements of group 3 from the 1D array.
*/
#include<stdio.h>
int main() {
    int a[3][3]={
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };

    int oneD[3*3];
    int row = 3, col = 3;
    int idx = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            oneD[idx]=a[i][j];
            idx++;
        }
    }

    //for group 3 means row 3 elements
    // (row-1)*col  to row*col -1 as it is 0 base indexing
    for(int i= (row-1)*col ; i<row*col; i++) {
        printf("%d ", oneD[i]);
    } 
    printf("\n");
}