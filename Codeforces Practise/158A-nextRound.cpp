#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int ans=0;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int num = nums[k-1];
    for(int i=0; i<n; i++){
        if(nums[i] >= num && nums[i]>0){
            ans++;
        }
    }
    cout << ans;
    return 0;
}