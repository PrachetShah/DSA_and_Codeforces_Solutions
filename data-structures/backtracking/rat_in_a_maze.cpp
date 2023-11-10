#include <bits/stdc++.h>

using namespace std;

bool isSafe(int Nx, int Ny,  vector<vector<bool>> & vis, 
vector < vector < int >> & arr, int n){
    if((Nx>=0 && Nx<n) && (Ny>=0 && Ny<n) && 
    (vis[Nx][Ny]==0) && (arr[Nx][Ny] == 1)){
        return true;
    }else{
        return false;
    }
}


void solve(int x, int y, vector < vector < int >> & arr, int n, vector<string> &ans, 
vector<vector<bool>> & vis, string path){
    // base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    // 4 movements -> DLRU
    vis[x][y] = 1;
    // Down
    if(isSafe(x+1, y, vis, arr, n)){        
        solve(x+1, y, arr, n, ans, vis, path+'D');
    }

    // Left
    if(isSafe(x, y-1, vis, arr, n)){
        solve(x, y-1, arr, n, ans, vis, path+'L');
    }

    // Right
    if(isSafe(x, y+1, vis, arr, n)){
        solve(x, y+1, arr, n, ans, vis, path+'R');
    }

    // Up
    if(isSafe(x-1, y, vis, arr, n)){
        solve(x-1, y, arr, n, ans, vis, path+'U');
    }
    vis[x][y] = 0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool> (n, 0));
    string path = "";

    if(arr[0][0]==0){
        return ans;
    }

    solve(0,0,arr,n,ans,visited,path);
    return ans;
}