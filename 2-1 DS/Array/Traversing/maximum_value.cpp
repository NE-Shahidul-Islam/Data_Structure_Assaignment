#include <bits/stdc++.h>
using namespace std;

int main()
{  
   int n;
   cin >> n;

   int arr[n];
   int max_value = INT64_MIN;
   for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > max_value) {
            max_value = arr[i];
        }
   }

   cout <<"Maximum Value of The Array is " <<max_value <<'\n';

    return 0;
}