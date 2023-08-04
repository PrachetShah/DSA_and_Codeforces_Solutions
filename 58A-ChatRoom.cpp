#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    string toFind = "hello";
    int j = 0;
    int pas = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i] == toFind[j]){
            j++;
            pas++;
        }
    }

    if(pas == 5){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}