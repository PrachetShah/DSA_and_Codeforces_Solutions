#include<bits/stdc++.h>

using namespace std;

int main(){
    string player;
    cin >> player;

    int check = 1;
    bool flag = false;

    for(int i=0; i<player.length()-1; i++){
        if(check >= 7){
            cout << "YES";
            flag = true;
            break;
        }
        if(player[i] == player[i+1]){
            check++;
        }else{
            check = 1;
        }
    }
    if(!flag && check >= 7){
        cout << "YES";
    }
    else if(!flag){
        cout << "NO";
    }
    
    return 0;
}