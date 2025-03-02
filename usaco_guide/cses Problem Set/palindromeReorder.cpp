#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007;

using ll = long long;
using vll = vector <ll>;
using ii = pair <ll, ll>;
using vii = vector <ii>;

const ll INF = ll(1E18)+16;


void tc(){
    string s;
    cin >> s;
    
    map<char, int> count;
    for(ll i=0; i<s.length(); i++){
        count[s[i]]++;
    }

    ll n = s.length();
    string ans = s;
    bool done = false;
    bool toPrint = true;

    if(n%2 == 0){
        ll i = 0;
        for(auto ch: count){
            if(ch.second%2 == 1){
                done = true;
                toPrint = false;
                cout << "NO SOLUTION\n";
                break;
            }else{
                for(int j=0; j<ch.second/2; j++){
                    ans[i] = ch.first;
                    ans[n-i-1] = ch.first;
                    i++;
                }
            }
        }
    }else{
        ll i = 0;
        for(auto ch: count){
            if(ch.second%2 == 1){
                ans[n/2] = ch.first;
                for(int j=0; j<ch.second/2; j++){
                    ans[i] = ch.first;
                    ans[n-i-1] = ch.first;
                    i++;
                }
                if(done){
                    toPrint = false;
                    cout << "NO SOLUTION\n";
                    break;
                }
                done = true;
            }else{
                for(int j=0; j<ch.second/2; j++){
                    ans[i] = ch.first;
                    ans[n-i-1] = ch.first;
                    i++;
                }
            }
        }
    }

    if(toPrint){
        cout << ans;
    }
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