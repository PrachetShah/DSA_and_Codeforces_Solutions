class Node:
    # constructor
    def __init__(self, value) -> None:
        self.data = value
        self.next = None
    # deconstructor
    def __del__(self):
        print("Node with", self.data, "deleted")

class CircularLL:
    def __init__(self, value) -> None:
        self.tail = Node(value)
        self.tail.next = self.tail
    
    # insertion
    def insertData(self, value):
        temp = Node(value)
        iter = self.tail
        temp.next = iter.next
        iter.next = temp
    
    def printLL(self) -> None:
        temp = self.tail
        map = {}
        # traverses till last
        while(temp.next):
            if map.get(temp.data):
                break
            print(temp.data, end=" -> ")
            map[temp.data] = 1
            temp = temp.next

ll = CircularLL(1)
ll.insertData(0)
ll.insertData(2)
ll.printLL()

print("\n\nDEONSTRUCTING DLL NOW")