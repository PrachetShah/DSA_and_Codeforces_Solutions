#include<bits/stdc++.h>

using namespace std;

/*
Since its a triangle, and the index can only move DOWN and Diagonal RIGHT
The index will never go out of bounds for any movement
so we only have one base case
*/

//----------------------------------------------------------------------
// Recursion TC: 2^(1+2+3+..+n) => 2^(n^2-n), since for row 1->1 col and 2 steps, row 2-> 2 col and 2^2 steps, and so on 
// SC: O(stackSpace) -> O(rows) -> O(n)
// Top Down Approach
int f(int i, int j, vector<vector<int>> triangle){
    // base case
    if(i==triangle.size()-1){
        return triangle[i][j];
    }
    int down = triangle[i][j] + f(i+1, j, triangle);
    int diagonal = triangle[i][j] + f(i+1, j+1, triangle);
    return min(down, diagonal);
}
int triangleRec(vector<vector<int>> triangle){
    return f(0, 0, triangle); 
}

//----------------------------------------------------------------------
// memoization TC: O(N*N), SC: O(N*N) + O(N) ; MAX since triangle + recursion
int fm(int i, int j, vector<vector<int>> &dp, vector<vector<int>> triangle){
    if(i==triangle.size()-1){
        return triangle[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int down = triangle[i][j] + fm(i+1, j, dp, triangle);
    int diagonal = triangle[i][j] + fm(i+1, j+1, dp, triangle);
    dp[i][j] = min(down, diagonal);
    return dp[i][j];
}
int triangleMem(vector<vector<int>> triangle){
    // at max, we will require nxn matrix for holding dp array
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return fm(0, 0, dp, triangle);
}

//----------------------------------------------------------------------
// Tabulation TC: O(N*N), SC: O(N*N)
// Bottom Up Approach -> So base case will be opposite of Recursion
// Rec: (0)->(n-1) ;; Tab: (n-1)->(0)
int triangleTab(vector<vector<int>> triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case
    for(int j=0; j<n; j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        // value of i in triangle is the number of values in a column (j)
        // tabulation will be opposite and start j = i
        for(int j=i; j>=0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

//----------------------------------------------------------------------
// For Space Optimisation, just carry the current row and the next row
// Since we only use dp[i+1][j], and dp[i+1][j+1] everyloop
// TC: O(N*N), SC: O(N)
int triangleSP(vector<vector<int>> triangle){
    int n = triangle.size();
    vector<int> nextRow(n, 0);
    
    // base case
    for(int i=0; i<n; i++){
        nextRow[i] = triangle[n-1][i];
    }

    for(int i=n-2; i>=0; i--){
        // next row will of size currentRow+1
        vector<int> curr(i+1, 0);
        // Col will start from i->0 since number of cols in row(i) = cols(j)
        for(int j=i; j>=0; j--){
            int down = triangle[i][j] + nextRow[j];
            int diagonal = triangle[i][j] + nextRow[j+1];
            curr[j] = min(down, diagonal);
        }
        nextRow = curr;
    }
    return nextRow[0];
}

//----------------------------------------------------------------------
// Main method
int main(){
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 2},
        {8, 9, 10, 4}
    };

    cout << "REC:\t" << triangleRec(triangle) << endl;
    cout << "MEM:\t" << triangleMem(triangle) << endl;
    cout << "TAB:\t" << triangleTab(triangle) << endl;
    cout << "SP:\t" << triangleSP(triangle) << endl;

    return 0;
}