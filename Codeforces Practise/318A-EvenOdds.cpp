#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n, k;

    cin >> n >> k;
    
    long long int pos;
    pos = (n+1)/2;

    if(k <= pos){
        cout << k*2 -1;
    }else{
        cout << (k-pos)*2;
    }
    return 0;
}