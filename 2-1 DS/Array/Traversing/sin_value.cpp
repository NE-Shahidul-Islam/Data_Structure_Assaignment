#include <bits/stdc++.h>
using namespace std;
const double pii = 3.14159;

int main()
{  
   int n;
   cin >> n;

  double arr[n];
   for (int i = 0; i < n; i++) {
        cin >> arr[i];
        double degree = arr[i]*pii/180;
        cout <<"Sine Value of index "<<i << " is " <<sin(degree) <<'\n';
   }
   stack < int > st;
   

    return 0;
}