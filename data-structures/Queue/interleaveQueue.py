# Interleave Queue

def solve(q:list):
    n = len(q)
    if n%2 == 1:
        print("Odd Numbered Q, cannot interleave")
        return
    newQ = []
    half = n//2
    for _ in range(half):
        newQ.append(q.pop(0))
    
    # Now, q=[4,5,6], newQ =[1,2,3]
    # Take from new and append itr to back, and pop front and add it to back
    while len(newQ) > 0:
        first = newQ.pop(0)
        q.append(first)
        q.append(q.pop(0))
    print("Interleaved Queue: ",q)
    

q = [1,2,3,4,5,6]
solve(q)