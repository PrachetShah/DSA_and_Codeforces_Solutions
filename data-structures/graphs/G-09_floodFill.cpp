#include<bits/stdc++.h>

using namespace std;

// can also be solved via DFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int ogCol = image[sr][sc];
        queue<pair<int, int>> q; 
        q.push({sr, sc});

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visited[x][y] = 1;
            image[x][y] = color;

            for(int i=0; i<4; i++){
                int nr = x+dir[i].first;
                int nc = y+dir[i].second;

                if(nr >= 0 && nr < n && nc>=0 && nc<m && visited[nr][nc] != 1 && image[nr][nc] == ogCol){
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};