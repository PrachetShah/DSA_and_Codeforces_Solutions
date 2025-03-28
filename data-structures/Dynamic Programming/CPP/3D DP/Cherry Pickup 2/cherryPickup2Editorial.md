### Before i start with solution ,do upvote so i can have motivation to create more such descriptive solutions for problems ⬆️

<hr/>

# Recursion Approach

    Cherry Pickup 2 OR Ninja and his friends -> 3D DP problem
    Alice starts at (0, 0) and Bob starts at (0, m-1)
    They cannot take same cell twice, so if one picks up, another picks up 0

    Express everything in (i1, j1), and (i2, j2)
    Explore all paths
    Give maximum sum possible

    Since we have a fixed starting point, and variable ending point, we will start recursion
    from the starting point

# Complexity

- Time complexity and Space Complexity:

```
    Top Down Approach
    Recursion  Gives Time Limit Exceeded on Leetcode
    TC:(3^n * 3^n) ~ Exponention
    SC: O(n) -> stack space
```

# Code

```cpp []
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
```

<hr/>

# Memoization Approach

    We can reduce the computation required for the recursion
    by having a DP storing the computed states
    The size of DP array would be
    Total States: i->(N) ; j1->(M) ; j2->(M)
    Hence DP would be -> [N]*[M]*[M] -> 3D DP

# Complexity

- Time complexity and Space Complexity:

```
Gives Memory Limit Exceeded on Leetcode
TC: O(num of states)*9 -> O(n * m * m)*9 (since 9 directions)
SC: O(n*m*m) + O(n) [Recursive Space]
```

# Code

```cpp []
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
```

<hr/>

# Tabulation Approach

    We can reduce the stack space required by Memoization
    using Bottom Up Tabulation Approach
    Total States: i->(N) ; j1->(M) ; j2->(M)
    Hence DP would be -> [N]*[M]*[M] -> 3D DP

# Complexity

- Time complexity and Space Complexity:

```
Passes on Leetcode (better than 72% on average)
TC: TC: O(num of states)*9 -> O(n*m*m)*9,
SC:O(n*m*m)
```

# Code

```cpp []
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
```

<hr/>

# Space Optimisation Approach

    We can reduce the space required by DP array since at each step
    we just need the (i+1)th row, and their states,
    so we can reduce the dp array by storing the nextRow
    state with space [M]*[M]

# Complexity

- Time complexity and Space Complexity:

```
Passes on Leetcode
TC: TC: O(num of states)*9 -> O(n*m*m)*9,
SC:O(m*m)
```

# Code

```cpp []
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
```

#### Upvote for more such descriptive editorials ⬆️
