from collections import deque

q = deque()
q.append(1)
q.append(2)
q.append(3)
print(q)
print(q.popleft())

de = deque()
de.append(1)
de.appendleft(2)
# de.pop()
# de.popleft()
print(de)
# de.clear()
print(de[0])
print(de[-1])
print(de)