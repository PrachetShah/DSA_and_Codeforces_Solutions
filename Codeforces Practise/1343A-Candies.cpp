#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    long long int n;
    for(int j=0; j<t; j++){
        cin >> n;
        long long int x;
        for(int i=2; i<30; ++i){
            /*
            Just take a look at the binary representation of numbers: we can notice that 2^0=1, 2^1=10, 2^2=100
            and so on. Thus 2^0=1,2^0+2^1=11, 2^0+2^1+2^2=111
            and so on. And if we add one to this number consisting of k
            ones then we get 2^k
            */

            int val = (1 << i) - 1;
            if(n%(val) == 0){
                // cerr << val << endl;
                cout << n/val << endl;
                break;
            }
        }
    }
    return 0;
}