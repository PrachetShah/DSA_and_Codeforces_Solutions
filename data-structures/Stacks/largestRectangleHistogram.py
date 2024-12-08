def nextSmall(heights):
    stack = [-1]
    ans = [-1 for _ in range(len(heights))]

    for i in range(len(heights)-1,-1,-1):
        while stack[-1]!=-1 and heights[stack[-1]] >= heights[i]:
            stack.pop()
        ans[i] = stack[-1]
        stack.append(i)
    return ans

def prevSmall(heights):
    stack = [-1]
    ans = [-1 for _ in range(len(heights))]

    for i in range(len(heights)):
        while stack[-1]!=-1 and heights[stack[-1]] >= heights[i]:
            stack.pop()
        ans[i] = stack[-1]
        stack.append(i)
    return ans

def largestRectangle(heights):
    n = len(heights)
    next = nextSmall(heights)
    prev = prevSmall(heights)
    
    area = 0
    for i in range(n):
        l = heights[i]
        # cases when all are same
        if next[i] == -1:
            next[i] = n
        b = next[i] - prev[i] - 1
        area = max(area, l*b)

    return area

def largestOptimal(heights):
    stack = []
    ans = 0
    n = len(heights)

    for i in range(len(heights)):
        while stack and heights[stack[-1]] >= heights[i]:
            temp = stack.pop()
            width = i if not stack else i - stack[-1] - 1
            ans = max(ans, heights[temp]*width)
        stack.append(i)
    
    while stack:
        temp = stack.pop()
        width = n if not stack else n - stack[-1] - 1
        ans = max(ans, heights[temp]*width)
    
    return ans


print(largestRectangle([2,1,5,6,2,3]))
print(largestRectangle([2,4]))
print(largestOptimal([2,1,5,6,2,3]))
print(largestOptimal([2,4]))