#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

const ll INF = ll(1E18)+16;

void tc(){
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a+b+c>=2){
            ans++;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ll t;
    // cin >> t;
    // while(t--){
    //     tc();
    // }
    tc();
    return 0;
}