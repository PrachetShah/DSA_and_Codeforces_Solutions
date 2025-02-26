#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll x, y;
        cin >> y >> x;

        if(y>x){
            ll ans = (y-1)*(y-1);
            ll add = 0;
            if(y%2!=0){
                add = x;
            }else{
                add = 2*y-x;
            }
            cout << ans + add << "\n";
        }else{
            ll ans = (x-1)*(x-1);
            ll add = 0;
            if(x%2==0){
                add = y;
            }else{
                add = 2*x-y;
            }
            cout << ans + add << "\n";
        }
    }
}