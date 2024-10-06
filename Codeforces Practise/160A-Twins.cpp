#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> coins(n);

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end(), greater<int>());

    int sum = accumulate(coins.begin(), coins.end(), 0);
    int ans = 0;
    bool flag = false;

    for(int i=0; i<coins.size(); i++){
        if(ans > sum-ans){
            cout << i << endl;
            flag = true;
            break;
        }else{
            ans += coins[i];
        }
    }

    // if sum is not greater then return all
    if(!flag){
        cout << coins.size();
    }

    return 0;
}