/*
Either take it or dont take it
for recursion use
since we want to know whether we can include the current index or not based on prevIndex
f(index, prevIndex)

For Memoization:
index: 0->n-1 && prevIndex: -1->n-1
So, DP -> [N]*[N+1] with coordinate change as -1->0, 0->1 (1-based indexing basically)
*/

#include<bits/stdc++.h>

using namespace std;


// RECURSION: TC: O(2^n), SC: O(n)
int f(int index, int prevIndex, vector<int> arr){
    // base case
    if(index==arr.size()){
        return 0;
    }

    // dont take
    int notTake = 0 + f(index+1, prevIndex, arr);
    int take = 0;
    // take if curr > prev, we can include it in length or cur is the first
    if(prevIndex==-1 || arr[index] > arr[prevIndex]){
        take = 1 + f(index+1, index, arr);
    }
    return max(notTake, take);
}

int longestIncreasingSubsequenceRecur(vector<int> arr){
    int maxLen = f(0, -1, arr);
    return maxLen;
}

// Memoization TC: O(N*N), SC: O(N*N) + O(N)
int fm(int index, int prevIndex, vector<int> arr, vector<vector<int>> &dp){
    // base case
    if(index==arr.size()){
        return 0;
    }

    if(dp[index][prevIndex+1] != -1){
        return dp[index][prevIndex+1];
    }
    // dont take 
    int notTake = 0 + fm(index+1, prevIndex, arr, dp);
    int take = 0;
    // take if curr > prev, we can include it in length or cur is the first
    if(prevIndex==-1 || arr[index] > arr[prevIndex]){
        take = 1 + fm(index+1, index, arr, dp);
    }
    dp[index][prevIndex+1] = max(take, notTake);
    return dp[index][prevIndex+1];
}

int longestIncreasingSubsequenceMem(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    int maxLen = fm(0, -1, arr, dp);
    return maxLen;
}

// TABULATION, TC: O(n^2), SC: O(n^2)
int longestIncreasingSubsequenceTab(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int index=n-1; index>=0; index--){
        for(int prev=index-1; prev>=-1; prev--){
            // dont take 
            int notTake = 0 + dp[index+1][prev+1];
            int take = 0;
            // take if curr > prev, we can include it in length or cur is the first
            if(prev==-1 || arr[index] > arr[prev]){
                take = 1 +dp[index+1][index+1];
            }
            dp[index][prev+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

// Space Optimisation TC: O(n^2), SP: O(N)
int longestIncreasingSubsequenceSP(vector<int> arr){
    int n = arr.size();
    vector<int>next(n+1, 0), cur(n+1, 0);

    for(int index=n-1; index>=0; index--){
        for(int prev=index-1; prev>=-1; prev--){
            // dont take 
            int notTake = 0 + next[prev+1];
            int take = 0;
            // take if curr > prev, we can include it in length or cur is the first
            if(prev==-1 || arr[index] > arr[prev]){
                take = 1 + next[index+1];
            }
            cur[prev+1] = max(take, notTake);
        }
        next = cur;
    }
    return next[0];
}

// OPTIMAL: TABULATION WITH ONE DP -> TC:O(N^2), SC: O(N)
// it will store the length of LIS and return max from DP as ans
int longestIncreasingSubsequenceOP(vector<int> nums){
    int n = nums.size();
    vector<int> dp(n, 1);

    for(int index=0; index<n; index++){
        for(int prev=0; prev<index; prev++){
            // if true, it means then it can form LIS with the prev
            if(nums[index] > nums[prev] && dp[index] < dp[prev]+1){
                dp[index] = dp[prev] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main(){
    // vector<int> arr = {10, 9, 7,2, 3, 5, 8, 101, 19};
    vector<int> arr = {1,2,2,3,3,3,4,5,6,7,3};

    cout << "REC:\t" << longestIncreasingSubsequenceRecur(arr) << endl;
    cout << "MEM:\t" << longestIncreasingSubsequenceMem(arr) << endl;
    cout << "TAB:\t" << longestIncreasingSubsequenceTab(arr) << endl;
    cout << "SP:\t" << longestIncreasingSubsequenceSP(arr) << endl;
    cout << "OP:\t" << longestIncreasingSubsequenceOP(arr) << endl;
}