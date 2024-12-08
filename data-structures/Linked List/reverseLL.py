class Node:
    def __init__(self, value) -> None:
        self.data:int = value
        self.next:Node = None

class LinkedList:
    def __init__(self, value):
        self.start = Node(value)
    
    def insert(self, value):
        temp = Node(value)
        temp.next = self.start
        self.start = temp
    
    def printLL(self):
        temp = self.start
        while(temp.next):
            print(temp.data,end=" -> ")
            temp = temp.next
        print(temp.data)
    
    def reverseList(self):
        prev = None
        curr = self.start

        while(curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        self.start = prev
    
    def reverseRecur(self):
        curr = self.start
        prev = None
        def solve(curr, prev):
            # base case
            if curr == None:
                self.start = prev
                return
            # solve
            forward = curr.next
            solve(forward, curr)
            curr.next = prev
        solve(curr, prev)
    
    def reverseHead(self):
        temp = self.start
        def solve(curr):
            if curr.next == None or curr == None:
                return curr
            temp = solve(curr.next)
            curr.next.next = curr
            curr.next = None
            return temp
        self.start = solve(temp)
            

    def findMiddle(self):
        slow = fast = self.start
        while(fast.next and fast.next.next):
            slow = slow.next
            fast = fast.next.next
        return slow

# im imporing this class definiation in other codes, so using name.main to run only when this code is called
if __name__ == "__main__":
    head = LinkedList(5)
    head.insert(4)
    head.insert(3)
    head.insert(2)
    head.insert(1)
    head.insert(0)

    head.printLL()

    # reversing list
    print("Reversing List:")
    head.reverseList()
    head.printLL()

    print("Middle of List is: ", head.findMiddle().data)

    print("Reversing List:")
    head.reverseRecur()
    head.printLL()


    print("Reversing List:")
    head.reverseHead()
    head.printLL()