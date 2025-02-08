from collections import defaultdict

n = int(input())
p = list(map(int, input().split()))

map = defaultdict(list)
for i in range(len(p)):
    map[p[i]].append(i+1)
# print(map)
#  
ans = []
for i in range(len(p)):
    ans.append(map[p[i]].pop())

for i in range(len(ans)-1):
    print(ans[i], end=" ")
print(ans[-1])



