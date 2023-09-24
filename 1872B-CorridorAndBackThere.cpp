#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int d,s,ans=INT_MAX;
        for(int i=0; i<n; i++){
            cin >> d >> s;
            ans = min(ans, d+(int)(s-1)/2);
        }
        cout << ans << endl;
    }
}