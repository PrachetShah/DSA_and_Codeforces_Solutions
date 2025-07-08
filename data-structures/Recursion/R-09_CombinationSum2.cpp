#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(int index, int target, vector<int> &curr, vector<vector<int>> &ans, vector<int> &candidates){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]){
              continue;  
            }
            if(candidates[i] > target){
                break;
            }
            curr.push_back(candidates[i]);
            solve(i+1, target-candidates[i], curr, ans, candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, target, curr, ans, candidates);
        return ans;
    }
};