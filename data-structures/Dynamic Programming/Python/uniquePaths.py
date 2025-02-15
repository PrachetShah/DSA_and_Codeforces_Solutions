# Count total number of ways from (0,0) to (n, m)

'''
For recursion, express problem in terms of index, and perform operation on index, and return required count
For 2D matrix, we represent in two indexes (i,j) -> (row. column)
Explore all paths, and do stuff (keep a visited array to keep track)
'''

def uniquePaths(n, m):
    def solve(x, y):
        if x==0 and y==0:
            return 1
        if x<0 or y <0:
            return 0
        up = solve(x, y-1)
        left = solve(x-1, y)
        return up + left
    possibleWays = solve(m-1, n-1)
    print("[REC]\tCount of Unique Paths is:",possibleWays)


def uniquePathsMemoization(n, m):
    # TC: O(n*m)
    # SC: O[(n-1)+(m-1)] + O(n*m) [DPArray]
    dp = [[-1 for _ in range(n)] for _ in range(m)]

    def solve(x, y):
        if x==0 and y==0:
            return 1
        if x<0 or y <0:
            return 0
        if dp[x][y] != -1:
            return dp[x][y]
        up = solve(x, y-1)
        left = solve(x-1, y)
        dp[x][y] = up + left
        return dp[x][y]
    possibleWays = solve(m-1, n-1)
    # print(dp)
    print("[MEM]\tCount of Unique Paths is:", possibleWays)

# Bottom Up Approach
def uniquePathsTabulation(n, m):
    # TC: O(n*m)
    # SC: O(n*m)
    dp = [[-1 for _ in range(n)] for _ in range(m)]

    dp[0][0] = 1

    for i in range(m):
        for j in range(n):
            if i==0 and j==0:
                continue
            up, left = 0, 0
            if i>0:
                up = dp[i-1][j]
            if j>0:
                left = dp[i][j-1]
            dp[i][j] = up + left
    
    print("[TAB]\tCount of Unique Paths is:",dp[m-1][n-1])
    return dp[m-1][n-1]

# Bottom Up Approach
def uniquePathsSpaceOptimised(n, m):
    # TC: O(n*m)
    # SC: O(n*m)
    prevRow = [0]*n
    prevRow[0] = 1

    for i in range(m):
        temp = [0]*n
        for j in range(n):
            if i==0 and j==0:
                temp[j] = 1
                continue
            temp[j] = prevRow[j] + temp[j-1]
        prevRow = temp
    
    print("[SP]\tCount of Unique Paths is:", prevRow[-1])

if __name__ == "__main__":
    print("-"*60)
    gridCol, gridRow = 3, 5
    print(gridCol,",", gridRow)
    uniquePaths(gridCol, gridRow)    
    uniquePathsMemoization(gridCol, gridRow)
    uniquePathsTabulation(gridCol, gridRow)
    uniquePathsSpaceOptimised(gridCol, gridRow)
    print("-"*60)
    
    gridCol, gridRow = 3 , 7
    print(gridCol,",", gridRow)
    uniquePaths(gridCol, gridRow)    
    uniquePathsMemoization(gridCol, gridRow)
    uniquePathsTabulation(gridCol, gridRow)
    uniquePathsSpaceOptimised(gridCol, gridRow)
    print("-"*60)