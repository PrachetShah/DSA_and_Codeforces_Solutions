#include<bits/stdc++.h>

using namespace std;


bool dfs(vector<vector<char>> board, int i, int j, int k, map<string, bool> &visited, string word){
    if(k == word.length()){
        return true;
    }
    string visitedKey = to_string(i)+","+to_string(j);

    if(i<0 || i>=board.size()|| j<0 || j>=board[0].size() || 
        word[k] != board[i][j] || visited[visitedKey]){
        return false;
    }
    
    // move in all directions
    visited[visitedKey] = true;
    bool res = dfs(board, i+1, j, k+1, visited, word) || dfs(board, i-1, j, k+1, visited, word) 
            || dfs(board, i, j+1, k+1, visited, word) || dfs(board, i, j-1, k+1, visited, word);
    visited[visitedKey] = false;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    unordered_map<char, int> wordCnt;
    int rows = board.size();
    int cols = board[0].size();
    map<string, bool> visited;

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            wordCnt[board[i][j]]++;
        }
    }

    // checking if grid contains proper words
    for(int i=0; i<word.length(); i++){
        int cnt = count(word.begin(), word.end(), word[i]);
        if(cnt > wordCnt[word[i]]){
            return false;
        }
    }

    // checking if another word count is less so reverse the string
    if(wordCnt[word[0]] > wordCnt[word[word.length()-1]]){
        reverse(word.begin(), word.end());
    }
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(word[0] == board[i][j]){
                if(dfs(board, i, j, 0, visited, word)){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word);
}