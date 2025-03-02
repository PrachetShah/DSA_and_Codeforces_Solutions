#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

using ll = long long;

// the argument is the input filename without the extension
void setIO(string s) {
	// freopen((s + ".in").c_str(), "r", stdin);
	// freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	// setIO("problemname");

    ll t;
    cin >> t;
    ll ans = 0;
    int i = 1;
    while(pow(5, i) <= t){
        ans += t/pow(5, i);
        i++;
    }
    cout << ans;
}