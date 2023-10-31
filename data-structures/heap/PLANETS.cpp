#include <bits/stdc++.h>
using namespace std;

#define ll long long

class compare{
    bool operator()(const pair<ll, ll> &lhs, const pair<ll, ll> &rhs) const{
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        else
            return lhs.first > rhs.first;
    }
};

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin. tie(NULL);
	int t;
	cin >> t;
	
	
	while(t--){
	    int q, ch;
        set<pair<ll, ll>, compare> one;
        set<pair<ll, ll>> two;
        int len = 1;
        int ind = 0;
        cin >> q;
        for (int i = 0; i < q; i++){
            cin >> ch;
            ll s;
            if (ch == 1){
                cin >> s;
                one.insert({s, len});
                two.insert({len++, s});
            }
            else if (ch == 2){
                auto it = one.find({two.begin()->second, two.begin()->first});
                one.erase(it);
                cout << two.begin()->first << ' ';
                two.erase(two.begin());
            }
            else{
                auto it = two.find({one.begin()->second, one.begin()->first});
                two.erase(it);
                cout << one.begin()->second << ' ';
                one.erase(one.begin());
            }
        }

        cout << '\n';
	}
	return 0;
}
