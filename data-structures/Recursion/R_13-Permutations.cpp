#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(int index,  vector<vector<int>> &ans, vector<int> nums){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(index+1, ans, nums);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<vector<int>> curr;
        solve(0, ans, nums);
        return ans;
    }
};