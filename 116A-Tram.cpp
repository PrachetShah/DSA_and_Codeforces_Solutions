#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int maxi = 0;
    int curr = 0;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        curr -= a;
        curr += b;
        maxi = max(curr, maxi);
    }
    cout << maxi;
}