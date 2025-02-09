'''
Recurrence Relation:
f(ind) = {
    if ind == 0:
        return 0
    fs = f(ind-1) + abs(arr[ind] - arr[ind-1])
    if index > 1:
        ss = f(ind-2) + abs(arr[ind] - arr[ind-2])
    return min(fs, ss)
}

For K such Possibilities, you will have to write for i+1, i+2, ...upto i+k index 
so relation becomes
f(ind) = {
    if ind == 0:
        return 0
    minStep = INT_MAX
    for(j=1; j<k; j++){
        if ind - j > 0:
            jump = (ind-j) + abs(arr[ind] - arr[ind-j])
            minStep = min(minStep, jump)
    }
    return minStep
}
'''
from frogJump import frongJumpSpaceOptimised

# converting recursion to DP by finding overlapping subproblem
def frogJumpDPwithK(arr, k):
    n = len(arr)
    dp = [0]*n
    dp[0] = 0
    
    for i in range(1, n):
        minStep = float('inf')
        for j in range(1, k+1):
            if i-j>=0:
                jump = dp[i-j] + abs(arr[i] - arr[i-j])
                minStep = min(jump, minStep)
        dp[i] = minStep
    return dp[n-1]


if __name__ == "__main__":
    arr = [[10, 30, 60, 10, 60, 50], [30, 10, 60, 10, 50]]
    for data in arr:
        print(f"DP with K Step:\t Minimum Energy by Frog for {data}:\t", frogJumpDPwithK(data, 2))
        print(f"SpaceOptimised:\t Minimum Energy by Frog for {data}:\t", frongJumpSpaceOptimised(data))
        print()