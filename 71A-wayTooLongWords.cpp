#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<string> words(t);
    for(int i=0; i<t; i++){
        cin >> words[i];
    }
    for(int i=0; i<words.size(); i++){
        int n = words[i].length();
        if(n > 10){
            words[i] = words[i][0] + to_string(n-2) + words[i][n-1];
            cout << words[i] << endl;;
        }else{
            cout << words[i] << endl;
        }
    }

    return 0;
}