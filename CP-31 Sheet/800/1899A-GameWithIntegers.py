t = int(input())

for _ in range(t):
    n = int(input())
    if (n+1)%3==0 or (n-1)%3==0:
        print("First")
    else:
        print("Second")