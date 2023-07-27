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
        // vector<string> sandwich(b+c+h, "1");

        // for(int i=0; i<b; i+=2){
        //     sandwich[i] = "b";
        // }
        // int i=0;
        // while(c>0 || h>0){
        //     if(sandwich[i] == "b"){
        //         if(c>0 && sandwich[i+2]=="b"){
        //             sandwich[i+1] = "t";
        //             c--;
        //         }else if(h>0 && sandwich[i+2]=="b"){
        //             sandwich[i+1] = "t";
        //             h--;
        //         }else{
        //             break;
        //         }
        //     }
        //     i += 2;
        // }
        // cout << i+1 << endl;
        // for(int i=0; i<sandwich.size(); i++){
        //     if(sandwich[i] == "1"){
        //         cout << i+1 << endl;
        //         break;
        //     }
        // }
        // cout << "BREAD LEFT: " << b << endl;
        // cout << ans << endl;
    }

    return 0;
}