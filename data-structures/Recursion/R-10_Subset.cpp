#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:
    void solve(int index, vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums){
        if(index == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        solve(index+1, curr, ans, nums);
        curr.pop_back();
        solve(index+1, curr, ans, nums);
    }
    public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, nums);
        return ans;
    }
};

template <typename T> void printDouble(vector<T> ans){
    for(auto subset: ans){
        cout << "[ ";
        for(auto val: subset){
            cout << val << " ";
        }
        cout << "]" << " ; ";
    }
}

int main(){
    vector<int> nums = {1,2,3};
    Solution obj = Solution();
    vector<vector<int>> ans = obj.subsets(nums);
    printDouble(ans);
}