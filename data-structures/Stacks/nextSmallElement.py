def nextSmall(nums):
    stack = [-1]
    ans = [-1 for _ in range(len(nums))]
    for i in range(len(nums)-1, -1, -1):
        while stack and stack[-1] >= nums[i]:
            stack.pop()
        ans[i] = stack[-1]
        stack.append(nums[i])
    return ans

nums = [2,1,4,3]
ans = nextSmall(nums)
print(nums)
print(ans)