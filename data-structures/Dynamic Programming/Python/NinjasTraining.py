'''
You are given 3 activities per day and each has certain points, your task is to have maximum points after all days but
two activities cannot be perfoemed on consecutive days
2D DP Problem
    |09  50  01|
    |10 100  11|

Greedy Fails here, so we explore all possible ways

1. Recursion
    - Express problem in terms of index (consider day as index)
    - Do stuff on index
    - Find Maximum
'''

def ninjaTrainingRecur(table):
    # here day is the index of array, and last is task performed at (day+1)
    # last will be 3 for (n-1) index, and afterwards it will be 0,1,2
    def f(day, last):
        if day == 0:
            maxx = 0
            for i in range(3):
                if i != last:
                    maxx = max(maxx, table[0][i])
            return maxx
        maximum = 0
        for i in range(3):
            if i != last:
                # On this day, i performed i'th task, so dont perform that for day-1
                points = table[day][i] + f(day-1, i)
                maximum = max(points, maximum)
        return maximum
    maximum = f(len(table)-1, 3)
    print("[RECU]:\tMaximum Merit for Ninja is:", maximum)

# based on the recursion tree, this will have lots of overlapping subproblems
def ninjaTrainingMemoization(table):
    '''
    To create DP Array, we have 2 states, ie DAY and LAST
    so, DAY ranges from (0, N), and LAST ranges from (0,1,2,3)
    So, DP Array -> [n]*[4]
    TC -> O(N*4*3)
    SC -> O(N*4) + O(N)
    '''
    dp = [[-1]*4 for _ in range(len(table))]
    def f(day, last, dp):
        if day==0:
            maxi = 0
            for i in range(3):
                if i != last:
                    maxi = max(maxi, table[0][i])
            return maxi
        
        if dp[day][last] != -1:
            return dp[day][last]
        
        maximum = 0
        for i in range(3):
            if i != last:
                points = table[day][i] + f(day-1, i, dp)
                maximum = max(maximum, points)
        dp[day][last] = maximum
        return maximum
    
    f(len(table)-1, 3, dp)
    # for row in dp:
    #     print(row)
    print(f"[MEMO]:\tMaximum Merit for Ninja is: {dp[len(table)-1][3]}")


def ninjaTrainingTabulation(table):
    '''
    TC -> O(N*4*3)
    SC -> O(N*4)
    '''
    n = len(table)
    tasks = 4 # total tasks (0,1,2,3)
    dp = [[-1]*tasks for _ in range(n)]
    # base case
    dp[0][0] = max(table[0][1], table[0][2])
    dp[0][1] = max(table[0][0], table[0][2])
    dp[0][2] = max(table[0][0], table[0][1])
    dp[0][3] = max(table[0][0], max(table[0][1], table[0][2]))
    
    # converting above recursion into this format
    for day in range(1, n):
        for last in range(4):
            dp[day][last] = 0
            for task in range(3):
                if task != last:
                    points = table[day][task] + dp[day-1][task]
                    dp[day][last] = max(dp[day][last], points)
    # for row in dp:
    #     print(row)
    print(f"[TABU]:\tMaximum Merit for Ninja is: {dp[len(table)-1][3]}")

def ninjaTrainingSpaceOpti(table):
    '''
    TC -> O(N*4*3)
    SC -> O(4)
    '''
    prevDay = [-1]*4
    prevDay[0] = max(table[0][1], table[0][2])
    prevDay[1] = max(table[0][0], table[0][2])
    prevDay[2] = max(table[0][0], table[0][1])
    prevDay[3] = max(table[0][0], max(table[0][1], table[0][2]))

    for day in range(1, len(table)):
        # keep a temp array to store current day vals, and then update prevDay with currDay
        temp = [-1]*4
        for last in range(4):
            temp[last] = 0
            for task in range(3):
                if task != last:
                    points = table[day][task] + prevDay[task]
                    temp[last] = max(points, temp[last])
        prevDay = temp
    print(f"[SP]:\tMaximum Merit for Ninja is: {prevDay[3]}")

if __name__ == "__main__":
    table = [[9, 50, 1], [10, 100, 5], [30, 20, 60]]
    print("-"*100)
    ninjaTrainingRecur(table)
    ninjaTrainingMemoization(table)
    ninjaTrainingTabulation(table)
    ninjaTrainingSpaceOpti(table)
    print("-"*100)