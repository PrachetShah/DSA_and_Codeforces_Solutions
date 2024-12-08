class NStack:
    def __init__(self, n, size) -> None:
        self.arr = [-1 for _ in range(size)]
        self.top = [-1 for _ in range(n)]
        self.freeSpot =  0
        self.next = [i+1 for i in range(size)]
        self.next[size-1] = -1

    def push(self, stack, value):
        if self.freeSpot == -1:
            print("Stack Overflow")
            return -1
        print(f"Adding {value} to Stack {stack}")
        index = self.freeSpot
        self.freeSpot = self.next[index]
        self.arr[index] = value
        self.next[index] = self.top[stack-1]
        self.top[stack-1] = index
    
    def pop(self, stack):
        if self.top[stack-1] == -1:
            print(f"Stack Underflow for stack {stack}")
            return -1
        print(f"Popping from Stack {stack}")

        index = self.top[stack-1]
        self.top[stack-1] = self.next[index]
        self.arr[index] = -1
        self.next[index] = self.freeSpot
        self.freeSpot = index


nstack = NStack(3, 6)
nstack.push(1, 6)
nstack.push(2, 9)
nstack.push(3, 5)
nstack.push(1, 24)
nstack.push(1, 24)
nstack.push(1, 24)
nstack.push(1, 24)
nstack.pop(1)
nstack.pop(1)
nstack.pop(2)
nstack.pop(2)
nstack.pop(3)

print(nstack.arr)