#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int k,n,w;
    cin >> k >> n >> w;

    long long req = k*(w*(w+1)/2);
    if(req <= n){
        cout << 0 << endl;
    }else{
        cout << req-n << endl;
    }
    return 0;
}