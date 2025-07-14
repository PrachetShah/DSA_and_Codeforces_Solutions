#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
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

    bool isSafe(int row, int col, vector<vector<int>> &board, int n, map<int, bool> &rowCheck,
    map<int, bool> &upDiag, map<int, bool> &lowDiag){
        if(rowCheck[row]) return false;

        if(lowDiag[row+col]) return false;

        if(upDiag[n-1+col-row]) return false;

        return true;
    }
    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n, map<int, bool> &rowCheck,
    map<int, bool> &upDiag, map<int, bool> &lowDiag){
        if(col == n){
            addSolution(ans, board, n);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, n, rowCheck, upDiag, lowDiag)){
                board[row][col] = 1;
                rowCheck[row] = 1, lowDiag[row+col] = 1, upDiag[n-1+col-row] = 1;
                solve(col+1, ans, board, n, rowCheck, upDiag, lowDiag);
                rowCheck[row] = 0, lowDiag[row+col] = 0, upDiag[n-1+col-row] = 0;
                board[row][col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n, 0));
        map<int, bool> rowCheck;
        map<int, bool> upDiag;
        map<int, bool> lowDiag;
        solve(0, ans, board, n, rowCheck, upDiag, lowDiag);
        return ans;
    }
};