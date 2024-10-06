t = int(input())

for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    
    nums.sort()

    for i in range(1, n):
        nums[i] = (nums[i] + nums[i-1])//2
    
    print(nums[n-1])