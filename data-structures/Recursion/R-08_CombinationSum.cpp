#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(int index, int target, vector<int> &curr, vector<int> &candidates, vector<vector<int>> &ans){
        if(target<0){
            return;
        }
        if(target == 0){
            ans.push_back(curr);
        }
        for(int i=index; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            // we dont send i+1 here since i can be duplicated
            if(candidates[i] <= target){
                solve(i, target-candidates[i], curr, candidates, ans);
            }
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, curr, candidates, ans);
        return ans;
    }
};