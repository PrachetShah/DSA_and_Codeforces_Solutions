#include<bits/stdc++.h>

using namespace std;

bool checkPalindrome(string a, int left, int right){
    while(left<right){
        if(a[left++] != a[right--]){
            return false;
        }
    }
    return true;
}

void dfs(string s, int index, vector<string> &comb, vector<vector<string>> &ans){
    if(index == s.length()){
        ans.push_back(comb);
        return;
    }

    for(int end=index+1; end<=s.length(); ++end){
        // decide partition
        bool isPal = checkPalindrome(s, index, end-1);
        if(isPal){
            // create partition
            comb.push_back(s.substr(index, end-index));
            dfs(s, end, comb, ans);
            comb.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> comb;
    dfs(s, 0, comb, ans);
    return ans;
}

int main(){
    return 0;
}