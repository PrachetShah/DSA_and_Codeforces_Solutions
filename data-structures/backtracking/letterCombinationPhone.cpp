#include<bits/stdc++.h>

using namespace std;

void dfs(string digits, int index, map<char, string> mapping, string &curr, vector<string> &ans){
    if(index == digits.length()){
        if(curr.length()>0)
            ans.push_back(curr);
        return;
    }
    string numVal = mapping[digits[index]];
    for(int i=0; i<numVal.length(); i++){
        curr.push_back(numVal[i]);
        dfs(digits, index+1, mapping, curr, ans);
        curr.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    map<char, string> mapping = {
        {'2',"abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> ans;
    string curr = "";
    dfs(digits, 0, mapping, curr, ans);
    return ans;
}

int main(){
    string s = "23";
    vector<string> ans = letterCombinations(s);
    for(auto s: ans){
        cout << s << " ";
    }
    cout << ans.size();
}