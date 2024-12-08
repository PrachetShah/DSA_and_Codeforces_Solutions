arr = [0,1,2,2,1,1,0,0,2]

# array
def sort_colors(arr) -> None:
    low = 0
    mid = arr[len(arr)//2]
    high = len(arr)-1

    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -=1

class Node:
    def __init__(self, data) -> None:
        self.value = data 
        self.next = None

class LinkedList:
    def __init__(self, data) -> None:
        self.head = Node(data)
    
    def insert(self, value):
        temp = Node(value)
        temp.next = self.head
        self.head = temp

    def printLL(self):
        temp = self.head
        while(temp.next):
            print(temp.value, end=" -> ")
            temp = temp.next
        print(temp.value)
    
    def getValue(self):
        return self.value

    def sort_dutch(self):
        curr = self.head
        zeroHead = Node(0)
        zeroTail = zeroHead

        oneHead = Node(0)
        oneTail = oneHead

        twoHead = Node(0)
        twoTail = twoHead
        
        while curr:
            value = curr.value
            if value == 0:
                zeroTail.next = curr
                zeroTail = curr
            elif value == 1:
                oneTail.next = curr
                oneTail = curr
            elif value == 2:
                twoTail.next = curr
                twoTail = curr
            curr = curr.next
        if oneHead.next is not None:
            zeroTail.next = oneHead.next
        else:
            zeroTail.next = twoHead.next
        
        oneTail.next = twoHead.next
        twoTail.next = None
        self.head = zeroHead.next


print(arr)
sort_colors(arr)
print(arr)

head = LinkedList(0)
head.insert(1)
head.insert(0)
head.insert(2)
head.insert(1)
head.insert(0)
head.insert(2)
head.printLL()
head.sort_dutch()
head.printLL()