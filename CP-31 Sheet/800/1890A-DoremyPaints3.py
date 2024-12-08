import math

t= int(input())
for _ in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    count = {}
    for num in nums:
        if num in count:    
            count[num] += 1
        else:
            count[num] = 1
    

    if len(count.keys()) >= 3:
        print("NO")
    else:
        vals = list(count.keys())
        if count[vals[0]]-count[vals[-1]] > 0:
            diff = count[vals[0]]-count[vals[-1]]
        else:
            diff = -(count[vals[0]]-count[vals[-1]])
        if diff <= 1:
            print('YES')
        else:
            print("NO") 