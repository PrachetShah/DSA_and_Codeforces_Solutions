t = int(input())

def is_sorted(nums):
    flag = True
    for i in range(len(nums)-1):
        if nums[i] > nums[i+1]:
            flag = False
            break
    return flag

for _ in range(t):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    if k>1 or is_sorted(nums):
        print("YES")
    else:
        print("NO")