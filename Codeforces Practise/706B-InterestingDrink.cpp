#include<bits/stdc++.h>

using namespace std;

// Solution using binary search and finding index
void solve(vector<int> shops, long long coins){
    int index = upper_bound(shops.begin(), shops.end(), coins) - shops.begin();
    cout << index << endl;
}

int main(){
    int n;
    cin >> n;

    vector<int> shops(n);
    for(int i=0; i<n; i++){
        cin >> shops[i];
    }
    // sorting shops for easy finding everytime
    sort(shops.begin(), shops.end());

    int q, ans;
    cin >> q;
    

    for(int i=0; i<q; i++){
        long long coins;
        cin >> coins;
        // using binary search -> initial
        int index = upper_bound(shops.begin(), shops.end(), coins) - shops.begin();
        cout << index << endl;
    }
    return 0;
}