// GETTING Memory Limit Exceeded
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll t;
    cin >> t;

    while(t--){
        ll n,m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<ll> lf(n), rg(n);
        lf[0] = -1;
        for (ll i = 0; i < n; ++i) {
            if (i > 0) lf[i] = lf[i - 1];
            if (s[i] == '0') lf[i] = i;
        }
        rg[n - 1] = n;
        for (ll i = n - 1; i >= 0; --i) {
            if (i + 1 < n) rg[i] = rg[i + 1];
            if (s[i] == '1') rg[i] = i;
        }
        
        set<pair<ll, ll>> st;
        for (ll i = 0; i < m; ++i) {
            ll l, r;
            cin >> l >> r;
            ll left = rg[l - 1], rr = lf[r - 1];
            if (left > rr) {
                st.insert({-1, -1});
            } else {
                st.insert({left, rr});
            }
        }
        
        cout << st.size() << endl;
    }

    return 0;
}