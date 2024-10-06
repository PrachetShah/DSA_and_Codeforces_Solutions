#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int countA=0, countD=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='A')
            countA++;
        else 
            countD++;
    }

    if(countA > countD){
        cout << "Anton";
    }else if(countA < countD){
        cout << "Danik";
    }else{
        cout << "Friendship";
    }

    return 0;
}