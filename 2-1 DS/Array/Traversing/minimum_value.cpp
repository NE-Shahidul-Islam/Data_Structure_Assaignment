#include <bits/stdc++.h>
using namespace std;

int main()
{  
   int n;
   cin >> n;

   int arr[n];
   int min_value = INT64_MAX;
   for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] < min_value) {
            min_value = arr[i];
        }
   }

   cout <<"Minimum Value of The Array is " <<min_value <<'\n';

    return 0;
}