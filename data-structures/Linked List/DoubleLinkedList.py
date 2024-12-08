class Node:
    # constructor
    def __init__(self, value) -> None:
        self.data = value
        self.next = None
        self.prev = None
    # deconstructor
    def __del__(self):
        print("Node with", self.data, "deleted")

class DoubleLL:
    def __init__(self, value) -> None:
        self.start = Node(value)
    
    # insertion
    def insertStart(self, value) -> None:
        temp = Node(value)
        temp.next = self.start
        self.start.prev = temp
        self.start = temp

    def insertEnd(self, value) -> None:
        temp = Node(value)
        iter = self.start
        while(iter.next):
            iter = iter.next
        iter.next = temp
        temp.prev = iter
    
    def insertMiddle(self, value) -> None:
        middle = fast = self.start
        while(fast.next and fast.next.next):
            middle = middle.next
            fast = fast.next.next
        
        nodeToInsert = Node(value)
        nodeToInsert.next = middle.next
        middle.next.prev = nodeToInsert
        middle.next = nodeToInsert
        nodeToInsert.prev = middle

    # deletion
    def deleteStart(self) -> None:
        if self.start.next == None:
            print("Only One Node Left, cannot delete")
            return
        
        temp = self.start.next
        temp.prev = None
        self.start.next = None
        self.start = temp
    
    def deleteEnd(self) -> None:
        if self.start.next == None:
            print("Only One Node Left, cannot delete")
            return
        temp = self.start
        while(temp.next):
            temp = temp.next
        temp.prev.next = None
        temp.prev = None
        del temp
    
    def reverseList(self):
        prevNode = None
        curr = self.start
        while(curr):
            prevNode = curr.prev
            curr.prev = curr.next
            curr.next = prevNode
            # traversing forward, since curr.prev contains next node
            curr = curr.prev
        # since prevNode.prev contains new Head
        self.start = prevNode.prev
    
    def printLL(self) -> None:
        temp = self.start
        # traverses till last
        while(temp.next):
            print(temp.data, end=" -> ")
            temp = temp.next
        # print last
        print(temp.data)

ll = DoubleLL(1)
ll.insertStart(0)
ll.insertStart(2)
ll.insertEnd(3)
ll.insertMiddle(5)
ll.insertMiddle(10)
ll.insertEnd(6)
ll.printLL()
ll.deleteStart()
ll.printLL()
ll.deleteEnd()
ll.printLL()
ll.insertEnd(100)
ll.printLL()

print("Reversing")
ll.reverseList()
ll.printLL()

print("\n\nDEONSTRUCTING DLL NOW")