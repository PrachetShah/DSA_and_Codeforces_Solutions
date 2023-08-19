#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        
        int cntOdd = 0;

        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x%2 != 0)
                cntOdd++;
        }

        if(cntOdd%2 == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}