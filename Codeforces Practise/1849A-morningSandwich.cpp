// Educational Contest 152
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int b,c,h;
        cin >> b >> c >> h;
        int ans = 0;

        if(c+h >= b-1){
            ans = b + b -1;
            cout << ans << endl;
        }else{
            int val = c+h;
            ans = val + val + 1;
            cout << ans << endl;
        }
    }

    return 0;
}