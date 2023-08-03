#include<bits/stdc++.h>

using namespace std;

int main(){
    long double n,m,a, temp;
    cin >> n >> m >> a;
    cout.precision(22);
    long double ans;
    if(m < n){
        temp = m;
        m = n;
        n = temp;
    }
    if(a >= m){
        cout << ceil(n/a);
    }else{
        cout << ceil(n/a)*ceil(m/a);
    }

    // cout << ans;
    return 0;
}