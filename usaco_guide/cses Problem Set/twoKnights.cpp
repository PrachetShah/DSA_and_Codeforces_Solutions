#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        long totalWays = (i*i*(i*i-1))/2;
        long attackWays = 4*(i-1)*(i-2);
        cout << totalWays - attackWays << "\n";
    }
}