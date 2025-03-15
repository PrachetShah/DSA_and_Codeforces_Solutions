/*
 * Combination sum with NO DUPLICATES
    TC: O(2^n)
    We can prune the backtrack process to reduce time taken like using if condition for cand[i]>target, etc
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
        // CHANGE 2
        if(i>index && candidates[i]==candidates[i-1]){
            continue;;
        }
        if(candidates[i] > target){
            break;
        }
        selected.push_back(candidates[i]);
        // CHANGE 3, since no duplicates
        dfs(candidates, i+1, target-candidates[i], selected, ans);
        selected.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> selected;
    vector<vector<int>> ans;
    // CHANGE 1
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target, selected, ans);
    return ans;
}