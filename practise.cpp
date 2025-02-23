#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ls = long unsigned;

void tc(){
    ll n;
    cin >> n;
    if(n==1){
        cout << 1;
    }else if(n<=3){
        cout << "NO SOLUTION";
    }else{
        for(ll i=2; i<=n; i+=2){
            cout << i << " ";
        }
        for(ll i=1; i<=n; i += 2){
            cout << i << " ";
        }
    }
}

int main(){
    tc();
}