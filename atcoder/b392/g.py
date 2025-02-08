n = int(input())
s = list(map(int, input().split()))

doubleMap = {i:i*2 for i in s}
print(doubleMap)

count = 0
pairs = set()
for i in range(n):
    for j in range(i+1, n):
        if s[i] + s[j] in doubleMap:
            pairs.add((i, j))
            count += 1
print(count)