#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
public:
    void solve(int index, vector<string> &curr, vector<vector<string>> &ans, string s){
        if(index == s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i-index+1));
                solve(i+1, curr, ans, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, curr, ans, s);
        return ans;
    }
};