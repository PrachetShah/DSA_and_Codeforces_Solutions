#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>> &board, char val){
        for(int i=0; i<board.size(); i++){
//             check row
            if(board[row][i]==val)
                return false;
//             check col
            if(board[i][col] == val)
                return false;
            
//             check 3*3 grid
            if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>> &board){
        int n = board.size();

        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                // empty col
                if(board[row][col] == '.'){
                    // iterate over all values
                    for(char val='1'; val<='9'; val++){
                        if(isSafe(row, col, board, val)){
                            board[row][col] = val;

                            bool solveAhead = solve(board);
                            if(solveAhead){
                                return true;
                            }else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    void printSudoku(vector<vector<char>>& board) {
        cout << "\n";
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
};


int main(){
    vector<vector<char>> board {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    s.printSudoku(board);
    s.solveSudoku(board);
    s.printSudoku(board);
    return 0;
}