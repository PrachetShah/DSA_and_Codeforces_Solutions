class NQueue:
    def __init__(self, n, size) -> None:
        self.arr = [-1 for _ in range(size)]
        self.rear = [-1 for _ in range(n)]
        self.freeSpot =  0
        self.next = [i+1 for i in range(size)]
        self.next[size-1] = -1

    def push(self, queue, value):
        if self.freeSpot == -1:
            print("Queue Overflow")
            return -1
        print(f"Adding {value} to queue {queue}")
        index = self.freeSpot
        self.freeSpot = self.next[index]
        self.arr[index] = value
        self.next[index] = self.rear[queue-1]
        self.rear[queue-1] = index
    
    def pop(self, queue):
        if self.rear[queue-1] == -1:
            print(f"queue Underflow for queue {queue}")
            return -1
        print(f"Popping from queue {queue}")

        index = self.rear[queue-1]
        self.rear[queue-1] = self.next[index]
        self.arr[index] = -1
        self.next[index] = self.freeSpot
        self.freeSpot = index


nqueue = NQueue(3, 6)
nqueue.push(1, 6)
nqueue.push(2, 9)
nqueue.push(3, 5)
nqueue.push(1, 24)
nqueue.push(1, 24)
nqueue.push(1, 24)
nqueue.push(1, 24)
nqueue.pop(1)
nqueue.pop(1)
nqueue.pop(2)
nqueue.pop(2)
nqueue.pop(3)

print(nqueue.arr)