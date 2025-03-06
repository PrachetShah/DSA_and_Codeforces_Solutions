#include<bits/stdc++.h>

using namespace std;

int mod = (int)(1e9+7);

void print(vector<vector<int>> a){
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a[0].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int solveRecur(int i, int j, vector<vector<int>> maze){
    if(i>=0 && j>=0 && maze[i][j] == -1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    int up = solveRecur(i, j-1, maze);
    int left = solveRecur(i-1, j, maze);
    return up + left;
}

int solveRecurMem(int i, int j, vector<vector<int>> maze, vector<vector<int>> &dp){
    if(i>=0 && j>=0 && maze[i][j] == -1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = solveRecurMem(i, j-1, maze, dp);
    int left = solveRecurMem(i-1, j, maze, dp);
    dp[i][j] = up+left;
    return dp[i][j];
}

void uniquePaths(vector<vector<int>> maze){
    int m = maze.size();
    int n = maze[0].size();
    int ans = solveRecur(m-1, n-1, maze);
    cout << "[REC]\tNumber of Ways in Maze: "<< ans%mod << "\n";

    vector<vector<int>> dp1(m, vector<int>(n, -1));
    int ans2 = solveRecurMem(m-1, n-1, maze, dp1);
    cout << "[MEM]\tNumber of Ways in Maze: "<< ans%mod << "\n";

    cout << "m:" << m << ", n: " << n << "\n";
    vector<vector<int>> tab(m, vector<int>(n, -1));
    tab[0][0] = 1;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(maze[i][j] == -1){
                tab[i][j] = 0;
                continue;
            }
            if(i==0 && j==0){
                tab[i][j] = 1;
                continue;
            }
            int up=0;
            int left=0;
            if(i> 0)
                up = tab[i-1][j];
            if(j>0)
                left = tab[i][j-1];
            tab[i][j] = up+left;
        }
    }
    print(tab);
    cout << "[TAB]\tNumber of Ways in Maze: "<< tab[m-1][n-1]%mod << "\n";
}

int main(){
    vector<vector<int>> maze = {
        {0, 0, 0},
        {0, -1, 0},
        {0, 0, 0}
    };
    uniquePaths(maze);
}