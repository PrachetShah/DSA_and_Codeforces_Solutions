#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    getline(cin, input);
    int length;
    cin >> length;
    string output = "";

    for(int i=0; i<input.length(); i++){
        if(input[i] == ' '){
            output += "%20";
        }else{
            output += input[i];
        }
    }

    cout << output;
    return 0;
}