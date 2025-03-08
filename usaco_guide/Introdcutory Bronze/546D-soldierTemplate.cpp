#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

// use it in bracket -> a%(MOD);
#define MOD 1000000007;
const int MOD_ANOTHER = 1e+9;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


void tc(vector<ll> fre){
    ll a, b;
    cin >> a >> b;
    cout << fre[a] - fre[b] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	// setIO("problemname");

    int t;
    cin >> t;
    vector<ll> fre(5000001, -1);
    vector<ll> spf(5000001, -1);
    
    for(int i=2; i*i <=5000001; i++){
        spf[i] = 1;
    }
    for(int i=2; i*i <= 5000001; i++){
        if(spf[i] == i){
            for(int j=i*i; j<= 5000001; j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
    for(ll i=1; i<=5000001; i++)
	{
		int temp=i,cnt=0;
		while(i!=1) {
			i/=spf[i];
			cnt++;
		}
		fre[temp] = cnt;
		i=temp;
	}
	for(int i=2 ; i<=5000001; i++)
	{
		fre[i] = fre[i]+fre[i-1];
	}

    while(t--){
        tc(fre);
    }
}