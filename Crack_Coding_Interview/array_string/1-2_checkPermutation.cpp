#include<bits/stdc++.h>

using namespace std;

int main(){
    string a,b;
    cout << "Enter String a: ";
    cin >> a;
    cout << "Enter String b: ";
    cin >> b;

    if(a.length() != b.length()){
        cout << "Not Permutation\n";
    }else{
        // 1. sort and check
        // 2. Hash Table
        bool flag = false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for(int i=0; i<a.length(); i++){
            if(a[i] != b[i]){
                cout << "Not Permutation\n";
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "Permuation of Each Other\n";
        }
    }
    return 0;
}