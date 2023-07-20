#include<bits/stdc++.h>

using namespace std;

int main(){
    int state;
    cin >> state;

    if(state > 0){
        cout << state;
    }else{
        int val1 = state/10;
        int val2 = state/100*10 + state%10;
        cout << max(val1, val2);
    }
    return 0;
}