#include<bits/stdc++.h> 

using namespace std;

int main(){
    string input;
    cin >> input;
    bool flag = false;

    for(int i=0; i<input.length(); i++){
        if(input[i] == 'H' || input[i]=='Q' || input[i]=='9'){
            cout << "YES";
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << "NO";
    }
    return 0;
}