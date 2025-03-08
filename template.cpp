#include <bits/stdc++.h>
using namespace std;

// MACROS
// use it in bracket -> a%(MOD);
// defining mod is not a good idea like this, better to declare it as global const, since it has to be surrounded by brackets
// #define MOD 1e9+7;
#define f first
#define s second

// Type Names
using ll = long long;
using vll = vector <ll>;
using pll = pair <ll, ll>;
using vpl = vector <pll>;

const ll INF = ll(1E18)+16;
const int MOD = 1e9+7;

template <class T> void print(vector<T> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void tc(){
    
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