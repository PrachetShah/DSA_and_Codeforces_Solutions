#include<bits/stdc++.h>

using namespace std;

int main(){
    string name;
    cin >> name;

    unordered_set<char> s;
    for(int i=0; i<name.length(); i++){
        s.insert(name[i]);
    }
    // cout << s.size() << endl;
    string ans = s.size()%2==0 ? "CHAT WITH HER!" : "IGNORE HIM!";
    cout << ans;
    return 0;
}