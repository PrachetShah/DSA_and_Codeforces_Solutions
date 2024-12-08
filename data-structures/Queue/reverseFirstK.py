from collections import deque

# using stack
def modifyQueue(q, k):
    # reverse first k and add it in stack
    stack =[]
    # step 1: fetch first k elements and reverse them
    for i in range(k):
        stack.append(q.popleft())
    
    # step 2: add the reversed ele in queue
    while stack:
        q.append(stack.pop())
    
    # step 3: remove the first n-k ele from queue and add it in back
    for i in range(n-k):
        q.append(q.popleft())
    return q
    

def modifyQueueDeque(q, k):
    # reverse first k and add it in stack
    d = deque()

    for i in range(k):
        d.appendleft(q.popleft())
    
    while d:
        q.append(d.popleft())
    
    for i in range(len(q)-k):
        q.append(q.popleft())
    return q 

