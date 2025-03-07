#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

void tc(){
    ll bronzeBefore, bronzeAfter;
    cin >> bronzeBefore >> bronzeAfter;

    ll silverBefore, silverAfter;
    cin >> silverBefore >> silverAfter;

    ll goldBefore, goldAfter;
    cin >> goldBefore >> goldAfter;

    ll platBefore, platAfter;
    cin >> platBefore >> platAfter;

    // start from end till you find not same
    ll goldToPlat = platAfter - platBefore;  
    ll silverToGold = goldAfter - goldBefore + goldToPlat;
    ll bronzeToSilver = silverAfter - silverBefore + silverToGold;
    
    cout << bronzeToSilver << endl;
    cout << silverToGold << endl;
    cout << goldToPlat << endl;
}

int main() {
	setIO("promote");

    tc();
}