#include <bits/stdc++.h>
using namespace std;

template <typename T> void print(vector<T> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

//----------------------------------------------------------------------
// Recursion TC: O(N*M), SC: O(PathLength)[m-1 + n-1]
int f(int i, int j, vector<vector<int>> a){
    // base case
    if(i==0 && j==0){
        return a[0][0];
    }
    if(i<0 || j<0){
        return 1e9;
    }

    int up = a[i][j] + f(i-1, j, a);
    int left = a[i][j] + f(i, j-1, a);
    return min(up, left);
}
int minPathRec(vector<vector<int>> grid){
    return f(grid.size()-1, grid[0].size()-1, grid);
}

//----------------------------------------------------------------------
// memoization TC: O(N*M), SC: O(N*M) + O(PathLength)[m-1 + n-1]
int fm(int i, int j, vector<vector<int>> &dp, vector<vector<int>> grid){
    if(i==0 && j==0){
        return grid[i][j];
    }
    if(i<0 || j<0){
        return 1e9;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = grid[i][j] + fm(i, j-1, dp, grid);
    int left = grid[i][j] + fm(i-1, j, dp, grid);
    dp[i][j] = min(up, left);
    return dp[i][j];
}
int minPathMem(vector<vector<int>> grid){
    int rows =grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));
    return fm(rows-1, cols-1, dp, grid);
}

//----------------------------------------------------------------------
// Tabulation TC: O(N*M), SC: O(N*M) + O(PathLength)[m-1 + n-1]
int minPathTab(vector<vector<int>> grid){
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i==0 && j==0){
                dp[i][j] = grid[i][j];
            }else{
                // base case, if i<0 or j<0
                int up = 1e9, left=1e9;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[rows-1][cols-1];
}

//----------------------------------------------------------------------
// For Space Optimisation, just carry the current row and the previous row
// Since we only use dp[i-1][j], and dp[i][j-1] everyloop
int minPathSP(vector<vector<int>> grid){
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<int> prevRow(cols, 0);
    
    for(int i=0; i<rows; i++){
        vector<int> currRow(cols, 0);
        for(int j=0; j<cols; j++){
            if(i==0 && j==0){
                currRow[j] = grid[i][j];
            }else{
                // base case, if i<0 or j<0
                int up = 1e9, left=1e9;
                if(i>0) up = grid[i][j] + prevRow[j];
                if(j>0) left = grid[i][j] + currRow[j-1];
                currRow[j] = min(up, left);
            }
        }
        prevRow = currRow;
    }

    return prevRow[cols-1];
}

//----------------------------------------------------------------------
// Main method
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << "REC:\t" << minPathRec(grid) << endl;
    cout << "MEM:\t" << minPathMem(grid) << endl;
    cout << "TAB:\t" << minPathTab(grid) << endl;
    cout << "SP:\t" << minPathSP(grid) << endl;
}