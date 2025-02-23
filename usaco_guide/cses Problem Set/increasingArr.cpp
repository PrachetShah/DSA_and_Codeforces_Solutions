#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ls = long unsigned;

void tc(){
    ll n;
    cin >> n;
    vector<ll> arr(n);

    for(int i=0; i<n; i++){
        ll val;
        cin >> val;
        arr[i] = val;
    }

    ll ans = 0;
    for(ll i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            ans += arr[i-1]-arr[i];
            arr[i] += arr[i-1]-arr[i];
        }
    }
    cout << ans;
}

int main(){
    tc();
}