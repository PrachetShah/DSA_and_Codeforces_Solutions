#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        long long num;
        cin >> num;

        if(num & 1){
            cout << "YES" << endl;
        }else{
            bool divisible = false;
            long long div = num;
            while(div > 2){
                div = div/2;
                if(div & 1){
                    if(num % div == 0){
                        divisible = true;
                        break;
                    }
                }
            }
            if(divisible){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}