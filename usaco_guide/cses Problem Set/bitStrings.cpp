#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

using ll = long long;
#define MOD 1000000007;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	// setIO("problemname");

    ll n;
    cin >> n;
    ll ans = 1;
    for(int i=0; i<n; i++){
        ans *= 2;
        ans %= MOD;
    }
    cout << ans;
}