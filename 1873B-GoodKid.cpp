#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        sort(arr, arr + n);
        long long int product = 1;
        arr[0]++;
        for(int i=0; i<n; i++){
            product *= arr[i];
        }

        cout << product << endl;
    }
}