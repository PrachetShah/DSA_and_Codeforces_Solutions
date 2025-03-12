def climbStairs(n):
    dp = [-1]*(n+1)
    dp[0], dp[1] = 1, 2
    def helper(n):
        if n <= 1:
            return 1
        if dp[n] == -1:
            dp[n] = helper(n-1) + helper(n-2)
        return dp[n]
    return helper(n)

def climbSP(n):
    first = 0
    second = 1
    for i in range(n):
        sum = first + second
        first, second = second, sum
    return sum

print("Num Ways of climbing stairs for n=5:", climbStairs(5))
print("Num Ways of climbing stairs for n=3:", climbSP(5))
print("Num Ways of climbing stairs for n=3:", climbStairs(3))
print("Num Ways of climbing stairs for n=3:", climbSP(3))
print("Num Ways of climbing stairs for n=3:", climbStairs(30))
print("Num Ways of climbing stairs for n=3:", climbSP(30))