#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        long long arr[n];

        vector<pair<long long, long long>> vec;
        for(long long i=0; i<n; i++){
            cin >> arr[i];
            arr[i] %= k;

            if(arr[i] == 0){
                arr[i] += k;
            }
            vec.push_back({-arr[i], i+1});
        }

        sort(vec.begin(), vec.end());
        for(auto i: vec){
            cout << i.second << " ";
        }
        cout << endl;
    }
}