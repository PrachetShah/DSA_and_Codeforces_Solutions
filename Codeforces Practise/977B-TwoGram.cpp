#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<string, int> count;

    for(int i=0; i<s.length()-1; i++){
        // cout << s.substr(i, 2) << endl;
        count[s.substr(i, 2)]++;
    }
    int val = 0;
    string ans;
    for(auto itr: count){
        if(itr.second >= val){
            ans = itr.first;
            val = itr.second;
        }
        // cout << itr.first << " " << itr.second << endl;
    }
    cout << ans << endl;
    return 0;
}