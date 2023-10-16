#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> prices(n);
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }

    // for(int i=0; i<n; i++){
    //     cout << prices[i] << " ";
    // }
    // cout << endl;

    sort(prices.begin(), prices.end());

    int ans = 0;
    for(int i=0; i<m; i++){
        // cout << i << " " << prices[i] << endl; 
        if(prices[i] > 0){
            break;
        }
        ans += -prices[i];
    }
    cout << ans << endl;

    return 0;
}