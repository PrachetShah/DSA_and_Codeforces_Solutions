#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    void DFS(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &visited){
        int n = board.size();
        int m = board[0].size();
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int nr = x + dir[i].first;
            int nc = y + dir[i].second;
            if(nr<0 || nc<0 || nr==n || nc==m) continue;
            if(board[nr][nc] == 'O' && !visited[nr][nc]){
                DFS(nr, nc, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        for(int i=0; i<n; i++){
            if(board[i][0]=='O' && !visited[i][0])
                DFS(i, 0, board, visited);
            if(board[i][m-1] == 'O' && !visited[i][m-1])
                DFS(i, m-1, board, visited);
        }

        for(int j=0; j<m; j++){
            if(board[0][j]=='O' && !visited[0][j])
                DFS(0, j, board, visited);
            if(board[n-1][j] == 'O' && !visited[n-1][j])
                DFS(n-1, j, board, visited);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

template<typename T> void printBoard(vector<vector<T>> board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution ans = Solution();
    cout << "Input:\n";
    printBoard(board);
    ans.solve(board);
    cout << "Output:\n";
    printBoard(board);    
}