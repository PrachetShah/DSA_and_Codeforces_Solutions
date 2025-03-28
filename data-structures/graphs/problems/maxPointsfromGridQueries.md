# Approach

Using minHeap and BFS Search to count points on sortedQueries so no need to start from zero everytime

# Complexity

- Time complexity:
  $$ O(klogk+n⋅mlog(n⋅m)) $$

- Space complexity:
  $$ O(n⋅m+k) $$

# Code

```cpp []
class Solution {
public:
using pii = pair<int, int>;
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<pair<int,int>> sortedQueries;
        for(int i=0; i<queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), 0);
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> minHeap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int points = 0;
        minHeap.push({grid[0][0], {0, 0} });
        visited[0][0] = true;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(auto [queryVal, queryIdx]: sortedQueries){
            while(!minHeap.empty() && minHeap.top().first < queryVal){
                auto [val ,pos] = minHeap.top();
                minHeap.pop();
                int row = pos.first, col = pos.second;
                points++;
                for(auto [dr, dc]: directions){
                    int nr = row+dr, nc = col+dc;
                    if(nr>=0 && nr<rows && nc>=0 && nc<cols && !visited[nr][nc]){
                        minHeap.push({grid[nr][nc], {nr, nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            result[queryIdx] = points;
        }
        return result;
    }
};
```
