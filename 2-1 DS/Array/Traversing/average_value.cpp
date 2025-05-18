#include <bits/stdc++.h>
using namespace std;

int main()
{  
   int n;
   cin >> n;

  int arr[n];
  int tot_value = 0;
   for (int i = 0; i < n; i++) {
        cin >> arr[i];
       tot_value += arr[i];
   }

   cout <<"Average Value of The Array is " <<(double)tot_value/n <<'\n';

    return 0;
}