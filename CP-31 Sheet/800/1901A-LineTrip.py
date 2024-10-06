t = int(input())

for _ in range(t):
    n, x = map(int, (input().split()))
    nums = list(map(int, input().split()))
    maxFuel = nums[0]-0
    for i in range(1, n):
        maxFuel = max(maxFuel, nums[i]-nums[i-1])
    maxFuel = max(maxFuel, 2*(x-nums[n-1]))
    print(maxFuel)