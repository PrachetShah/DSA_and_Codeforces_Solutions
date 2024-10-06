#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,t;
    cin >> s;
    cin >> t;

    reverse(s.begin(), s.end());
    bool flag = true;
    
    for(int i=0; i<s.length(); i++){
        if(s[i] != t[i]){
            cout << "NO" << endl;
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl;
    }
}