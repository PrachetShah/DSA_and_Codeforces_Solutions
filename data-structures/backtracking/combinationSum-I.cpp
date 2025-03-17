/*
 * Combination sum with DUPLICATES ALLOWED
 * TC: O(2^n) in the worst case, as we explore all subsets of candidates
*/
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> candidates, int index, int target, vector<int> &selected, vector<vector<int>> &ans){
    if(target < 0){
        return;
    }
    if(target == 0){
        ans.push_back(selected);
    }
    for(int i=index; i<candidates.size(); i++){
        selected.push_back(candidates[i]);
        // we dont send i+1 here since i can be duplicated
        dfs(candidates, i, target-candidates[i], selected, ans);
        selected.pop_back();
    }
}
vector<vector<int>> combinationSumI(vector<int>& candidates, int target) {
    vector<int> selected;
    vector<vector<int>> ans;
    dfs(candidates, 0, target, selected, ans);
    return ans;
}