#include<bits/stdc++.h>

using namespace std;


const vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

// dfs based approach
void dfs(int row, int col,vector<vector<char>> &grid, int rows, int cols){
    if(row<0 || col<0 || row>=rows || col>=cols || grid[row][col]!='1'){
        return;
    }
    grid[row][col] = '#';
    dfs(row+1, col, grid, rows, cols);
    dfs(row-1, col, grid, rows, cols);
    dfs(row, col+1, grid, rows, cols);
    dfs(row, col-1, grid, rows, cols);
}

// bfs based approach using queues
void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<string>> grid, int rows, int cols){
    visited[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    // perform bfs in all directions

    while(!q.empty()){
        auto val = q.front();
        int r = val.first;
        int c = val.second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;

            if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]=="1" && !visited[nr][nc]){
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
}

int numIslands(vector<vector<string>> grid){
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    int islands = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(!visited[i][j] && grid[i][j] == "1"){
                islands++;
                bfs(i, j, visited, grid, rows, cols);
            }
        }
    }
    return islands;
}

int main(){
    vector<vector<string>> grid = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
    int islands = numIslands(grid);
    cout << "Number of Islands: " << islands;
}