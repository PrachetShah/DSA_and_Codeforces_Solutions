/*
Prerequisite for this is Subset Equal to Sum K
Since here, we need to find subsets with sum (TotalSum)/2
Here,
    If sum of array is K
    then to partition it into 2 subsets, each subset should have sum as K/2
    If total sum == ODD, them the partition is not possible
    else we can find subset with sum as TARGET(K)/2 => since we find a subset 
    with sum K/2, then remanining elements will be of sum K/2;
    
    So question becomes, given an array, check if we can get subset with sum K/2
*/

#include<bits/stdc++.h>

using namespace std;

// Recursion, GIVES MLE on Leetcode
// TC: O(2^n)
// SC: O(N)
bool f(int index, int target, vector<int> nums){
    if(target == 0){
        return true;
    }
    if(index==0){
        return target==nums[0];
    }
    bool dontTake = f(index-1, target, nums);
    bool take = false;
    if(target >= nums[index]){
        take = f(index-1, target-nums[index], nums);
    }
    return (dontTake || take);
}
bool partitionEqualSubsetRec(vector<int> nums){
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if(totalSum%2==1){
        return false;
    }
    return f(nums.size()-1, totalSum/2, nums);
}

// Memoization, GIVES TLE on Leetcode
// TC: O(N*T)
// SC: O(N*T + N)
int fm(int index, int target, vector<vector<int>> &dp, vector<int> nums){
    if(target==0){
        return 1;
    }
    if(index==0){
        return target==nums[0];
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    int dontTake = fm(index-1, target, dp, nums);
    int take = 0;
    if(target >= nums[index]){
        take = fm(index-1, target-nums[index], dp, nums);
    }
    dp[index][target] = (dontTake | take);
    return dp[index][target];
}
bool partitionEqualSubsetMem(vector<int> nums){
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if(totalSum%2==1){
        return false;
    }
    vector<vector<int>> dp(nums.size(), vector<int>(totalSum/2+1, -1));
    return fm(nums.size()-1, totalSum/2, dp, nums);
}

// Tabulation
// TC: O(N*T)
// SC: O(N*T)
bool paritionEqualSubsetTab(vector<int> nums){
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if(totalSum%2==1){
        return false;
    }

    int target = (totalSum/2);
    vector<vector<bool>> dp(nums.size(), vector<bool>(target+1, false));
    // base case
    for(int i=0; i<nums.size(); i++){
        dp[i][0] = true;
    }
    // imp since if nums[0] > target, then will be heap overflow
    if(nums[0] < target) dp[0][nums[0]] = true;

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

bool partitionEqualSubsetSP(vector<int> nums){
    int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
    if(totalSum & 1) return false;
    bool dp[halfSum+1]; memset(dp, false, sizeof dp);
    dp[0] = true;                              // 0 sum is always achievable
    for(int num : nums) 
        for(int j = halfSum; j >= num; j--)    // essential to start right to left
            if(dp[j - num])                    // if j - num was previously achievable
                dp[j] = true;                  // we can add num to it and make j achievable as well
        
    return dp[halfSum];
}

// Bit masking
bool partitionEqualSubsetBit(vector<int> nums){
    int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
    if(totalSum & 1) return false;
    bitset<10001> dp(1);       // 0 is always achievable => dp[0] = 1
    for(int num : nums) 
        dp = dp | dp << num;
    return dp[halfSum];
}

template <typename T> void print(vector<T> arr){
    for(auto n: arr){
        cout << n << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {1,5,11,5};
    vector<int> nums2 = {1,2,3,5};

    cout << "Subset Equal to Sum K:\n";
    cout << "-----------------" << endl << "Arr: ";
    print(nums);
    cout << "REC:\t" << (partitionEqualSubsetRec(nums) ? "True" : "False") << endl;
    cout << "MEM:\t" << (partitionEqualSubsetMem(nums) ? "True" : "False") << endl;
    cout << "TAB:\t" << (paritionEqualSubsetTab(nums) ? "True" : "False") << endl;
    cout << "TAB:\t" << (partitionEqualSubsetSP(nums) ? "True" : "False") << endl;
    cout << "TAB:\t" << (partitionEqualSubsetBit(nums) ? "True" : "False") << endl;

    cout << "-----------------" << endl << "Arr: ";
    print(nums2);
    cout << "REC:\t" << (partitionEqualSubsetRec(nums2) ? "True" : "False")<< endl;
    cout << "MEM:\t" << (partitionEqualSubsetMem(nums2) ? "True" : "False")<< endl;
    cout << "TAB:\t" << (paritionEqualSubsetTab(nums2) ? "True" : "False")<< endl;
    cout << "TAB:\t" << (partitionEqualSubsetSP(nums2) ? "True" : "False")<< endl;
    cout << "TAB:\t" << (partitionEqualSubsetBit(nums2) ? "True" : "False")<< endl;

    return 0;
}