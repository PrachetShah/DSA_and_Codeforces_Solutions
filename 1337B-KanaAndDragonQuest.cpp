#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int x, voidAbsorption, lightingStrike;
        cin >> x >> voidAbsorption >> lightingStrike;
        while(voidAbsorption && x>0 && floor(x/2)+10 < x){
            voidAbsorption--;
            x = x/2 + 10;
        }
        if(x <= lightingStrike*10){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}