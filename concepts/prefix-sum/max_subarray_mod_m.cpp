/*
Given an array of n elements and an integer m. The task is to find the maximum value of the sum of its subarray modulo m i.e find 
the sum of each subarray mod m and print the maximum value of this modulo operation.

The idea is to compute prefix sum of array. We find maximum sum ending with every index and finally return the overall maximum. 
To find maximum sum ending at an index, we need to find the starting point of maximum sum ending with i.

Below steps explain how to find the starting point.

```
Let prefix sum for index i be prefixi, i.e., 
prefixi = (arr[0] + arr[1] + .... arr[i] ) % m

Let maximum sum ending with i be, maxSumi. 
Let this sum begins with index j.

maxSumi = (prefixi - prefixj + m) % m
                   
From above expression it is clear that the
value of maxSumi becomes maximum when 
prefixj is greater than prefixi 
and closest to prefixi
```
*/


#include<bits/stdc++.h>

using namespace std;

int maxSubarray(int arr[], int n, int m){
    int prefix=0, maxim=0;
    set<int> s;
    s.insert(0);

    for(int i=0; i<n; i++){
        prefix = (prefix+arr[i])%m;
        maxim = max(maxim, prefix);

        auto it = s.lower_bound(prefix+1);

        if(it != s.end()){
            maxim = max(maxim, prefix-(*it)+m);
        }

        s.insert(prefix);
    }

    return maxim;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = { 3, 3, 9, 9, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 7;
    cout << maxSubarray(arr, n, m) << endl;

    return 0;
}