#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

const ll INF = ll(1E18)+16;

void tc(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k,n,w;
    cin >> k >> n >> w;
    ll borrow = 0;

    ll total = k*((w*(w+1))/2);

    if(total > n){
        borrow = total - n;
    }
    cout << borrow;
    return 0;
}