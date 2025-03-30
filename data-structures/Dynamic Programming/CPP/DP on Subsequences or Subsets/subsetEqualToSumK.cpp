#include<bits/stdc++.h>

using namespace std;

// Recursion  
// TC:(2^n) ~ Exponential since 2 choices at each step
// SC: O(n) -> stack space
// Top Down Approach
bool f(int i, int target, vector<int> nums){
    if(target == 0){
        return true;
    }
    if(i==0){
        return nums[0]==target;
    }
    bool dontTake = f(i-1, target, nums);
    bool take = false;
    if(target >= nums[i]){
        take = f(i-1, target-nums[i], nums);
    }
    return (dontTake || take);
}
bool subsetEqualToKRec(int target, vector<int> nums){
    return f(nums.size()-1, target, nums);
}


// Memoization -> Changing States of target, and index
// Total States: i->(N) ; target->(Target)
// Hence DP would be -> [N]*[T] -> 2D DP
// TC: O(N*Target), SC:O(N*T) + O(n)
int fm(int i, int target, vector<vector<int>> &dp, vector<int> nums){
    if(target == 0){
        return true;
    }
    if(i==0){
        return nums[0]==target;
    }
    if(dp[i][target] != -1){
        return dp[i][target];
    }
    int dontTake = fm(i-1, target, dp, nums);
    int take = 0;
    if(target >= nums[i]){
        take = fm(i-1, target-nums[i], dp, nums);
    }
    dp[i][target] = (dontTake || take) ? 1 : 0;
    return dp[i][target];
}
int subsetEqualToKMem(int target, vector<int> nums){
    vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
    return fm(nums.size()-1, target, dp, nums);
}

// Tabulation
// Bottom Up Approach
// Total States: i->(N) ; target->(Target)
// Hence DP would be -> [N]*[T] -> 2D DP
// TC: O(N*T) , SC:O(N*T)
int subsetEqualToKTab(int target, vector<int> nums){
    vector<vector<bool>> dp(nums.size(), vector<bool> (target+1, false));

    // base case
    for(int i=0; i<nums.size(); i++){
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;

    // explore all
    for(int i=1; i<nums.size(); i++){
        // it will got to (<=) target, sinze it is inclusive
        for(int j=1; j<= target; j++){
            int dontTake = dp[i-1][j];
            int take = 0;
            if(j >= nums[i]){
                take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = (dontTake || take) ? 1 : 0;
        }
    }
    return dp[nums.size()-1][target];
}

// SP
// TC: O(N*T), SC: O(T)
int subsetEqualToKSP(int target, vector<int> nums){
    vector<bool> prevRow(target+1, false);
    vector<bool> curr(target+1, 0);
    // base case
    prevRow[0] = curr[0] = true;

    // explore all
    for(int i=1; i<nums.size(); i++){
        // it will got to (<=) target, sinze it is inclusive
        for(int j=1; j<= target; j++){
            int dontTake = prevRow[j];
            int take = 0;
            if(j >= nums[i]){
                take = prevRow[j-nums[i]];
            }
            curr[j] = (dontTake || take) ? 1 : 0;
        }
        prevRow = curr;
    }
    return prevRow[target];
}

template <typename T> void print(vector<T> arr){
    for(auto n: arr){
        cout << n << " ";
    }
    cout << endl;
}


int main(){
    vector<int> nums = {4,3,2,1};
    vector<int> nums2 = {1,7,2,9,10};
    int target = 5;
    int target2 = 6;

    cout << "Subset Equal to Sum K:\n";
    cout << "-----------------" << endl << "Arr: ";
    print(nums);
    cout << "REC1:\t" << (subsetEqualToKRec(target, nums) ? "True" : "False") << endl;
    cout << "MEM:\t" << (subsetEqualToKMem(target, nums) ? "True" : "False")<< endl;
    cout << "TAB:\t" << (subsetEqualToKTab(target, nums) ? "True" : "False")<< endl;
    cout << "SP:\t" << (subsetEqualToKSP(target, nums) ? "True" : "False")<< endl;

    cout << "-----------------" << endl << "Arr: ";
    print(nums2);
    cout << "REC:\t" << (subsetEqualToKRec(target2, nums2) ? "True" : "False") << endl;
    cout << "MEM:\t" << (subsetEqualToKMem(target2, nums2) ? "True" : "False")<< endl;
    cout << "TAB:\t" << (subsetEqualToKTab(target2, nums2) ? "True" : "False")<< endl;
    cout << "SP:\t" << (subsetEqualToKSP(target2, nums2) ? "True" : "False")<< endl;

    return 0;
}