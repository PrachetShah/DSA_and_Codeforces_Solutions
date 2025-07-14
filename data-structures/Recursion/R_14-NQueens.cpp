#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<int>> &board, int n){
        int x = row, y = col;
        while(y>=0){
            if(board[x][y] == 1){
                return false;
            }
            y--;
        }

        x=row, y=col;
        // check diagonal
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }

        x=row, y=col;
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n){
        vector<string> val;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<n; j++){
                if(board[i][j] == 0){
                    temp += ".";
                }else{
                    temp += "Q";
                }
            }
            val.push_back(temp);
        }
        ans.push_back(val);
    }
    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n){
        if(col == n){
            addSolution(ans, board, n);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 1;
                solve(col+1, ans, board, n);
                board[row][col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(0, ans, board, n);
        return ans;
    }
};