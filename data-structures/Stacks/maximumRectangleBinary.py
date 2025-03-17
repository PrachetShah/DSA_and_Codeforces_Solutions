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

def maximumBinaryRectangle(matrix):
    ans = largestOptimal(matrix[0])

    for i in range(1, len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] != 0:
                matrix[i][j] += matrix[i-1][j]
        ans = max(ans, largestOptimal(matrix[i]))

    return ans

