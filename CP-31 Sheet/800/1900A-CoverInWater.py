t = int(input())

output = []

for _ in range(t):
    n = int(input())
    flow = input()
    flip = []
    for char in flow:
        flip.append(char)
    count = 0
    if '...' in flow:
        print(flow.count('...')*2)
    else:
        print(flow.count('.'))