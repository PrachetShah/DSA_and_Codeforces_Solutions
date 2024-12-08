from collections import deque


d = deque()

def solve(q, k):
    d = deque()
    ans = []
    for i in range(k):
        if q[i] < 0:
            d.append(i)
    
    if len(d)>0:
        ans.append(q[d[0]])
    else:
        ans.append(0)

    for i in range(k, len(q)):
        # removal logic
        if len(d)>0 and i-d[0] >= k:
            d.popleft()
        # addition
        if q[i] < 0:
            d.append(i)
        
        if len(d)>0:
            ans.append(q[d[0]])
        else:
            ans.append(0)
    return ans


q = [-8, 2, 3, -6, 10]
k = 2
ans = solve(q, k)
print(ans)