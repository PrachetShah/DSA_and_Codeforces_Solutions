from collections import defaultdict, deque

def solve(stream):
    count = defaultdict(int)
    d = deque()
    ans = ""

    for char in stream:
        count[char] += 1
        d.append(char)

        while len(d):
            if count[d[0]] > 1:
                # repeating
                d.popleft()
            else:
                # non-repeating
                ans += d[0]
                break
        
        if len(d)==0:
            ans += "#"
    return ans

stream = "aabc"
ans = solve(stream)
print(ans)