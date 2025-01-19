def maxSumNonAdjacentMemoization(arr):
    n = len(arr)
    dp = [-1]*n

    def f(index):
        if index == 0:
            return arr[index]
        if index < 0:
            return 0
        
        if dp[index] != -1:
            return dp[index]
        
        pick = arr[index] + f(index-2)
        notPick = 0 + f(index-1)
        return max(pick, notPick)

    return f(n-1)

def maxSumTabulation(arr):
    n = len(arr)
    dp = [0]*n 
    dp[0] = arr[0]

    for i in range(1, n):
        pick = arr[i]
        if i > 1:
            pick = arr[i] + dp[i-2]
        notPick = 0 + dp[i-1]
        dp[i] = max(pick, notPick)
    
    return dp[n-1]

def maxSumSpaceOptimised(arr):
    n = len(arr)

    prev = arr[0]
    prev2 = 0

    for i in range(1, n):
        pick = arr[i]
        if i > 1:
            pick = arr[i] + prev2
        notPick = 0 + prev

        curr = max(pick, notPick)
        prev2 = prev
        prev = curr
    
    return prev

if __name__ == "__main__":
    arrs = [[1,2,3,9], [3,3,3,3,3,3]]

    for arr in arrs:
        print("MEMOI\tMaximum Sum of Non Adjacent Elements is", maxSumNonAdjacentMemoization(arr))
        print("TABUL\tMaximum Sum of Non Adjacent Elements is", maxSumTabulation(arr))
        print("SPACE\tMaximum Sum of Non Adjacent Elements is", maxSumSpaceOptimised(arr))
        print()