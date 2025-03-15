#include<bits/stdc++.h>

using namespace std;

/*
    O(3^L * M * N), where:  
    M is the number of rows in the board.
    N is the number of columns in the board.
    L is the length of the target word.

    We need to search for the word starting from every cell in the (𝑀×𝑁) board.

    At each step in the recursion, we move in one of four possible directions (up, down, left, right).
    However, we cannot move back to the previous character, so effectively we have at most 3 choices per step 
    (except for the first move). Since we need to find a word of length L, the worst case results in a branching factor 
    of 3 for each of the remaining L−1 characters.
    Thus, the recursive call tree has O(3^L) complexity.
*/

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

    // OPTIMISATION to save time, checking if another word count is less so reverse the string
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