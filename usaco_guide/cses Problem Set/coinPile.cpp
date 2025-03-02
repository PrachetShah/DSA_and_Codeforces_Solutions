#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

const ll INF = ll(1E18)+16;

void tc(){
    ll a,b;
    cin >> a >> b;
    
    if((2*a-b)<0 || (2*b-a)<0 || (2*a-b)%3!=0 || (2*b-a)%3!=0){
        cout << "NO\n";
    }else{
        cout << "YES\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        tc();
    }

    return 0;
}