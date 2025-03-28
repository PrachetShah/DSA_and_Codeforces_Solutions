#include<bits/stdc++.h>

using namespace std;

// Doing this for MAX Path sum, for MIN Path, change bas case and conditions (Min is done below)
// It can only go in 3 directions from the index, so taking max from each row wont give correct

//----------------------------------------------------------------------
/* Recursion 
    TC: 3^(n) -> 3 since 3 directons (exponential in nature)
    SC: O(n)
    Top Down Approach
*/
int f(int i, int j, vector<vector<int>> grid){
    // base case
    if(j<0 || j >=grid[0].size()){
        return -1e9; // out of bounds
    }
    if(i==0){
        return grid[i][j];
    }
    int up = grid[i][j] + f(i-1, j, grid);
    int leftDiag = grid[i][j] + f(i-1, j-1, grid);
    int rightDiag = grid[i][j] + f(i-1, j+1, grid);
    return max(up, max(leftDiag, rightDiag));
}
int fallingPathSumRec(vector<vector<int>> grid){
    int maxPath = 0;
    int m = grid[0].size(); //cols
    int n = grid.size(); // rows

    for(int j=0; j<m; j++){
        maxPath = max(maxPath, f(n-1, j, grid));
    }
    return maxPath; 
}

//----------------------------------------------------------------------
// memoization TC: O(N*M), SC: O(N*M) + O(N) ; MAX since fallingPathSum + recursion
int fm(int i, int j, vector<vector<int>> &dp, vector<vector<int>> grid){
    // base case
    if(j<0 || j>=grid[0].size()){
        return -1e9;
    }
    if(i==0){
        return grid[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = grid[i][j] + fm(i-1, j, dp, grid);
    int leftDiag = grid[i][j] + fm(i-1, j-1, dp, grid);
    int rightDiag = grid[i][j] + fm(i-1, j+1, dp, grid);
    dp[i][j] = max(up, max(leftDiag, rightDiag));
    return dp[i][j];
}
int fallingPathSumMem(vector<vector<int>> grid){
    // at max, we will require nxn grid for holding dp array
    int n = grid.size();
    int m = grid[0].size();
    int maxPath = 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int j=0; j<m; j++){
        maxPath = max(maxPath, fm(n-1, j, dp, grid));
    }
    return maxPath;
}

//----------------------------------------------------------------------
// Tabulation TC: O(N*M), SC: O(N*M)
// Bottom Up Approach -> So base case will be opposite of Recursion
int fallingPathSumTab(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // base case
    for(int j=0; j<m; j++){
        dp[0][j] = grid[0][j];
    }
    int maxSum = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int up = grid[i][j] + dp[i-1][j];
            int leftDiag = grid[i][j], rightDiag = grid[i][j];
            if(j>0) leftDiag += dp[i-1][j-1];
            if(j+1<m) rightDiag += dp[i-1][j+1];
            dp[i][j] = max(up, max(leftDiag, rightDiag));
        }
    }
    for(int j=0; j<m; j++){
        maxSum = max(dp[n-1][j], maxSum);
    }
    return maxSum;
}

//----------------------------------------------------------------------
// For Space Optimisation
// TC: O(N*M), SC: O(M)
int fallingPathSumSP(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prevRow = grid[0];

    for(int i=1; i<n; i++){
        vector<int> currRow(m, 0);
        for(int j=0; j<m; j++){
            int up = grid[i][j] + prevRow[j];
            int leftDiag = grid[i][j], rightDiag = grid[i][j];
            if(j>0) leftDiag += prevRow[j-1];
            if(j+1<m) rightDiag += prevRow[j+1];
            currRow[j] = max(up, max(leftDiag, rightDiag));
        }
        prevRow = currRow;
    }
    int maxSum = 0;
    for(int j=0; j<m; j++){
        maxSum = max(prevRow[j], maxSum);
    }
    return maxSum;
}

// BONUS: Min Path Sum
int minFallingPathSum(vector<vector<int>> grid) {
    int n = grid.size();
    vector<int> prevRow = grid[0];

    for(int i=1; i<n; i++){
        vector<int> currRow(n, 0);
        for(int j=0; j<n; j++){
            int up = grid[i][j] + prevRow[j];
            int leftDiag = 1e9, rightDiag = 1e9;
            if(j>0) leftDiag = grid[i][j] + prevRow[j-1];
            if(j+1<n) rightDiag = grid[i][j] + prevRow[j+1];
            currRow[j] = min(up, min(leftDiag, rightDiag));
        }
        prevRow = currRow;
    }
    int mini = 1e9;
    for(int j=0; j<n; j++){
        mini = min(mini, prevRow[j]);
    }
    return mini;
}

//----------------------------------------------------------------------
// Main method
int main(){
    vector<vector<int>> grid = {
        {1, 1, 100},
        {2, 2, 3},
        {3, 10, 2},
        {8, 9, 10}
    };
    
    cout << "-----------------" << endl;
    cout << "Max Path Sum:\n";
    cout << "REC:\t" << fallingPathSumRec(grid) << endl;
    cout << "MEM:\t" << fallingPathSumMem(grid) << endl;
    cout << "TAB:\t" << fallingPathSumTab(grid) << endl;
    cout << "SP:\t" << fallingPathSumSP(grid) << endl;
    
    vector<vector<int>> grid2 = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << "-----------------" << endl;
    cout << "Min Path Sum: " << minFallingPathSum(grid2);
    return 0;
}