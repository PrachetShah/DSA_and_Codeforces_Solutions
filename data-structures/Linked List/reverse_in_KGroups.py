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
    
    def reverseKGrp(self, k):
        curr = self.start
        def solve(head, k):
            # base
            if head == None:
                return head
            # step 1: reverse first k nodes
            count = 0
            curr = head
            prev = forward = None
            while(curr and count < k):
                forward = curr.next
                curr.next = prev
                prev = curr
                curr = forward
                count += 1
            # step2: recursion sambhal lega
            if(forward):
                head.next = solve(forward, k)
            # step3: return head of reverse list
            return prev
        self.start = solve(curr, k)


head = LinkedList(5)
head.insert(4)
head.insert(3)
head.insert(2)
head.insert(0)
head.printLL()

head.reverseKGrp(2)
head.printLL()

head.reverseKGrp(3)
head.printLL()