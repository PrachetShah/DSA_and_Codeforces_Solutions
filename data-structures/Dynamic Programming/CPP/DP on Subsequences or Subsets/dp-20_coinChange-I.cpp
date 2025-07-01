/*
Get Minimum number of coins from denominations to form a target
-> represent in index format
-> to take, not take approach
-> recursion returns no. of coins

RECURSION
-> base case will be
    if(index==0){
        if(T%nums[0]==0){
            return T/nums[0];
        }else{
            return 1e9;   SOMETHING LARGE(but not INT_MAX) since that will cause overflow
        }
    }
        returns min(take, notTake)
    TC: O(Exponential) since its greater than O(2^n)
    SC: O(more) since its stanfding in same index, even space will be a lot O(target)

MEMOIZATION
dp array will be of size [N]*[target+1]
TC: O(N*T)
SC: O(N*T) + O(T)

Tabulation
*/

#include<bits/stdc++.h>

using namespace std;

// RECURSION
int f(int index, int T, vector<int> &nums){
    if(index==0){
        if(T%nums[0] == 0){
            return T/nums[0];
        }else{
            return 1e9;
        }
    }
    int notTake = 0 + f(index-1, T, nums);
    int take = INT_MAX;
    if(nums[index] < T){
        take = 1 + f(index, T-nums[index], nums);
    }
    return min(notTake, take);
}

int coinChangeRecur(vector<int> nums, int target){
    int ans = f(nums.size()-1, target, nums);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

// MEMOIZATION
int FM(int index, int T, vector<int> &nums, vector<vector<int>> &dp){
    if(index==0){
        if(T%nums[0] == 0){
            return T/nums[0];
        }else{
            return 1e9;
        }
    }
    if(dp[index][T] != -1){
        return dp[index][T];
    }
    int notTake = 0 + FM(index-1, T, nums, dp);
    int take = INT_MAX;
    if(nums[index] < T){
        take = 1 + FM(index, T-nums[index], nums, dp);
    }
    dp[index][T] = min(notTake, take);
    return dp[index][T];
}

int coinChangeMem(vector<int> nums, int target){
    vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
    int ans = FM(nums.size()-1, target, nums, dp);
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

// Tabulation
int coinChangeTab(vector<int> nums, int target){
    vector<vector<int>> dp(nums.size(), vector<int>(target+1, 0));

    for(int T=0; T<=target; T++){
        if(T%nums[0] == 0){
            dp[0][T] = T/nums[0];
        }else{
            dp[0][T] = 1e9;
        }
    }

    for(int index=1; index<nums.size(); index++){
        for(int T=0; T<=target; T++){
            int notTake = 0 + dp[index-1][T];
            int take = INT_MAX;
            if(nums[index] <= T){
                take = 1 + dp[index][T-nums[index]];
            }
            dp[index][T] = min(take, notTake); 
        }
    }

    int ans = dp[nums.size()-1][target];
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

// Space Optimisation
int coinChangeSP(vector<int> nums, int target){
    vector<vector<int>> dp(nums.size(), vector<int>(target+1, 0));
    vector<int> prev(target+1, 0), cur(target+1, 0);

    for(int T=0; T<=target; T++){
        if(T%nums[0] == 0){
            prev[T] = T/nums[0];
        }else{
            prev[T] = 1e9;
        }
    }

    for(int index=1; index<nums.size(); index++){
        for(int T=0; T<=target; T++){
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if(nums[index] <= T){
                take = 1 + cur[T-nums[index]];
            }
            cur[T] = min(take, notTake); 
        }
        prev = cur;
    }
    // since for array with length 1, cur will not be updated at all
    int ans = prev[target];
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,3};
    int target = 7;
    cout << "REC:\t" << coinChangeRecur(nums, target) << endl;
    cout << "MEM:\t" << coinChangeMem(nums, target) << endl;
    cout << "TAB:\t" << coinChangeTab(nums, target) << endl;
    cout << "SP:\t" << coinChangeSP(nums, target) << endl;
}