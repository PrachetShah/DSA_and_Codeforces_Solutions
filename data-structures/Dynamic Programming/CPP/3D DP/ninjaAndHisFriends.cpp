/*
    Cherry Pickup 2 OR Ninja and his friends -> 3D DP problem
    Alice starts at (0, 0) and Bob starts at (0, m-1)
    They cannot take same cell twice, so if one picks up, another picks up 0
    
    Express everything in (i1, j1), and (i2, j2)
    Explore all paths
    Give maximum sum possible

    Since we have a fixed starting point, and variable ending point, we will start recursion
    from the starting point
*/

#include<bits/stdc++.h>

using namespace std;

// Recursion  Gives Time Limit Exceeded on Leetcode
// TC:(3^n * 3^n) ~ Exponention
// SC: O(n) -> stack space
// Top Down Approach
// Since both move together, there i (row) will be common
int f(int i, int j1, int j2, vector<vector<int>> grid){
    // BASE CASE
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()){
        return -1e8;
    }
    // at every step, you will move to same row, so both will reach destination at the same time
    if(i==grid.size()-1){
        // if they reach at same col, then add only once, or both will be added
        if(j1 == j2){
            return grid[i][j1];
        }else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    // explore all paths
    // in total 9 combinations of path to track for each movement
    int maxi = -1e9;
    for(int dj1 = -1; dj1 <=1; dj1++){
        for(int dj2 = -1; dj2<=1; dj2++){
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }else{
                value = grid[i][j1] + grid[i][j2];
            }
            value += f(i+1, j1+dj1, j2+dj2, grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}
int cherryPickup2Rec(vector<vector<int>> grid){
    int i=0, j1=0;
    int j2=grid[0].size()-1;
    return f(i, j1, j2, grid);
}


// Memoization -> Gives Memory Limit Exceeded on Leetcode
// Total States: i->(N) ; j1->(M) ; j2->(M)
// Hence DP would be -> [N]*[M]*[M] -> 3D DP
// TC: O(num of states)*9 -> O(n*m*m)*9, SC:O(n*m*m) + O(n)
int fm(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>> grid){
    // BASE CASE
    if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()){
        return -1e8;
    }
    // at every step, you will move to same row, so both will reach destination at the same time
    if(i==grid.size()-1){
        // if they reach at same col, then add only once, or both will be added
        if(j1 == j2){
            return grid[i][j1];
        }else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    // explore all paths
    // in total 9 combinations of path to track for each movement
    int maxi = -1e9;
    for(int dj1=-1; dj1 <=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }else{
                value = grid[i][j1] + grid[i][j2];
            }
            value +=  fm(i+1, j1+dj1, j2+dj2, dp, grid);
            maxi = max(maxi, value);
        }
    }
    dp[i][j1][j2] = maxi;
    return dp[i][j1][j2];
}
int cherryPickup2Mem(vector<vector<int>> grid){
    int i=0, j1=0;
    int j2=grid[0].size()-1;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, -1)));
    return fm(i, j1, j2, dp, grid);
}

// Tabulation
// Bottom Up Approach
// Total States: i->(N) ; j1->(M) ; j2->(M)
// Hence DP would be -> [N]*[M]*[M] -> 3D DP
// TC: O(num of states)*9 -> O(n*m*m)*9, SC:O(n*m*m)
int cherryPickup2Tab(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (m, 0)));
    // base case
    for(int j1=0; j1<m; j1++){
        for(int j2=0; j2<m; j2++){
            if(j1==j2){
                dp[n-1][j1][j2] = grid[n-1][j1];
            }else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }
    // explore paths -> 3 states, so 3 loops
    for(int i=n-2; i>=0; i--){
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j1];
                        }else{
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if((j1+dj1>=0 && j1+dj1<m) && (j2+dj2>=0 && j2+dj2<m))
                            value +=  dp[i+1][j1+dj1][j2+dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}

// SP
// 3D DP optimised to 2D DP
int cherryPickup2SP(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> nextRow (m, vector<int> (m, 0));
    // base case
    for(int j1=0; j1<m; j1++){
        for(int j2=0; j2<m; j2++){
            if(j1==j2){
                nextRow[j1][j2] = grid[n-1][j1];
            }else{
                nextRow[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }
    // explore paths -> 3 states, so 3 loops
    for(int i=n-2; i>=0; i--){
        vector<vector<int>> currRow (m, vector<int> (m, 0));
        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int value = 0;
                        if(j1 == j2){
                            value = grid[i][j1];
                        }else{
                            value = grid[i][j1] + grid[i][j2];
                        }
                        if((j1+dj1>=0 && j1+dj1<m) && (j2+dj2>=0 && j2+dj2<m))
                            value +=  nextRow[j1+dj1][j2+dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                currRow[j1][j2] = maxi;
            }
        }
        nextRow = currRow;
    }

    return nextRow[0][m-1];
}


int main(){
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

    cout << "-----------------" << endl;
    cout << "Cherry Pickup 2:\n";
    cout << "REC:\t" << cherryPickup2Rec(grid) << endl;
    cout << "MEM:\t" << cherryPickup2Mem(grid) << endl;
    cout << "TAB:\t" << cherryPickup2Tab(grid) << endl;
    cout << "SP:\t" << cherryPickup2SP(grid) << endl;
}