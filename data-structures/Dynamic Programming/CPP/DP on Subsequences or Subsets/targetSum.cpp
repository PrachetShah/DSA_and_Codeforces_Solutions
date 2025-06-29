#include<bits/stdc++.h>

// find target sum by assigning signs
// this is very similar to dividing subset into two partitions where (S1-S2 = D)
const int MOD = 1e9+7;

using namespace std;

int findWays(vector<int> nums, int target){
    int n = nums.size();
    vector<int> prev(target+1, 0);
    if(nums[0] == 0){
        prev[0] = 2;
    }else{
        prev[0] = 1;
    }
    if(nums[0] !=0 && nums[0]<=target){
        prev[nums[0]] = 1;
    }

    for(int index=1; index<n; index++){
        vector<int> curr(target+1, 0);
        for(int sum=0; sum<=target; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(nums[index] <= sum){
                take = prev[sum-nums[index]];
            }
            curr[sum] = (notTake + take);
        }
        prev = curr;
    }
    return prev[target];
}

// count partitions where s1-s2 = d
int countPartition(int d, vector<int> nums){
    int totSum = accumulate(nums.begin(), nums.end(), 0);
    if(totSum-d <0 || totSum%2){
        return false;
    }
    return findWays(nums, (totSum-d)/2);
}

int targetSumRec(int target, vector<int> nums){
    return countPartition(target, nums);
}



int main(){
    vector<int> nums = {1,2,3,1};
    int target = 3;

    cout << "REC\t" << targetSumRec(target, nums) << endl;
}