#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    if(n==1){
        cout << 1;
    }else{
        int ans = 1;
        int max_ans = INT_MIN;
        int pointer = 1;
        while(pointer < nums.size()){
            if(nums[pointer] >= nums[pointer-1]){
                ans++;
            }else{
                max_ans = max(max_ans, ans);
                ans = 1;
            }
            pointer++;
        }
        max_ans = max(max_ans, ans);
        cout << max_ans;
    }
    return 0;
}