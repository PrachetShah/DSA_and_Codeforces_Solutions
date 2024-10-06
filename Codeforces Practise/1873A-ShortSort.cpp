#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    string in = "abc";
    while(t--){
        string sen;
        cin >> sen;
        int countDisplacement = 0;
        for(int i=0; i<3; i++){
            if(sen[i] != in[i]){
                countDisplacement++;
            }
        }
        if(countDisplacement > 2){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}