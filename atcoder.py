from collections import defaultdict

n = int(input())
p = list(map(int, input().split()))

map = {}
for i in range(len(p)):
    if p[i] not in map:
        map[p[i]] = []
    map[p[i]].append(i+1)
# print(map)
#  
ans = []
for i in range(len(p)):
    ans.append(map[p[i]].pop(-1))

# print(" ".join(map(int, ans)))
for i in range(len(ans)):
    print(ans[i], end=" ")