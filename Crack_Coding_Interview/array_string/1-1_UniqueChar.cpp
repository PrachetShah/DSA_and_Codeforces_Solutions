#include<bits/stdc++.h>

using namespace std;

int main(){
    string input;
    cout << "Enter String: ";
    cin >> input;

    vector<bool> arr(26, false);
    bool flag = false;
    for(int i=0; i<input.length(); i++){
        if(arr[input[i] - 'a']){
            cout << "Not Unique\n";
            flag = true;
            break;
        }
        arr[input[i] - 'a'] = true;
    }

    if(!flag){
        cout << "Unique\n";
    }
    return 0;
}