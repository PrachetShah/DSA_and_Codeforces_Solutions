#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> vals = {a+b+c, a*b*c, a+(b*c), (a*b)+c, (a+b)*c, a*(b+c)};

    int ans = INT_MIN;
    for(int i=0; i<6; i++){
        ans = max(ans, vals[i]);
    }    
    cout << ans << endl;
    return 0;
}