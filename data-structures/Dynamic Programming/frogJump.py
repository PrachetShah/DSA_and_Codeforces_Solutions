# converting problem to recursive
def frogJumpRecursion(arr):
    def helper(index):
        if index == 0:
            return 0
        oneStep = helper(index-1) + abs(arr[index]- arr[index-1])
        if index > 1:
            twoStep = helper(index-2) + abs(arr[index]- arr[index-2])
        else:
            twoStep = helper(index-1) + abs(arr[index]- arr[index-1])
        return min(oneStep, twoStep)
    return helper(len(arr)-1)

# converting recursion to DP by finding overlapping subproblem
def frogJumpDP(arr):
    n = len(arr)
    dp = [0]*n
    dp[0] = 0
    dp[1] = dp[0] + abs(arr[0] - arr[1])
    for i in range(2, n):
        left = dp[i-1] + abs(arr[i] - arr[i-1])
        right = dp[i-2] + abs(arr[i] - arr[i-2])
        dp[i] = min(left, right)
    return dp[n-1]

# converting DP to space optimised DP with two vars
def frongJumpSpaceOptimised(arr):
    n = len(arr)
    twoBack = 0
    oneBack = twoBack + abs(arr[1] - arr[0])
    for i in range(2, n):
        left = oneBack + abs(arr[i] - arr[i-1])
        right = twoBack + abs(arr[i] - arr[i-2])
        # changing the value of two variables
        oneBack, twoBack = min(left, right), oneBack
    return oneBack

if __name__ == "__main__":
    arr = [[10, 30, 60, 10, 60, 50], [30, 10, 60, 10, 50]]
    for data in arr:
        print(f"RECUR:\t\t Minimum Energy by Frog for {data}:\t", frogJumpRecursion(data))
        print(f"DP:\t\t Minimum Energy by Frog for {data}:\t", frogJumpDP(data))
        print(f"SpaceOptimised:\t Minimum Energy by Frog for {data}:\t", frongJumpSpaceOptimised(data))
        print()