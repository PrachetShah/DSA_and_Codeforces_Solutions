#include <bits/stdc++.h> 

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val){
    for(int i=0; i<board.size(); i++){
        // row check
        if(board[row][i] == val)
            return false;

        // col check
        if(board[i][col] == val)
            return false;
        
        // check matrix 3*3
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board){

    int n = board[0].size();
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            // empty cell
            if(board[row][col] == 0){
                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;
                        
                        // recursive call
                        bool solveAhead = solve(board);
                        if(solveAhead)
                            return true;
                        else{
                            // backtrack
                            board[row][col] = 0;
                        }
                        
                    }
                }
                return false;
            }
        }
    }
    return true;

}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}

void printSudoku(vector<vector<int>>& board) {
    cout << "\n";
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    vector<vector<int>> board {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };

    printSudoku(board);
    solveSudoku(board);
    printSudoku(board);
    return 0;
}