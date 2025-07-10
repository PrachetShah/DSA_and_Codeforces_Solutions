#include<bits/stdc++.h>

using namespace std;

class Solution{
    private:
    void solve(int index, vector<int> &curr, vector<vector<int>> &ans, vector<int> &nums){
        ans.push_back(curr);
        for(int i=index; i<nums.size(); i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(i+1, curr, ans, nums);
            curr.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
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
    vector<int> nums = {1,2,2};
    Solution obj = Solution();
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    printDouble(ans);
}