class Node:
    def __init__(self, data):
        self.data = data 
        self.next = None

def reverse(head:Node):
    prev = None
    curr = head
    temp = None

    while curr:
        temp = curr.next
        curr.next = prev
        prev = curr
        curr = temp
    
    return prev

def checkPalindrome(head:Node):
    if head is None or head.next is None:
        return True
    
    slow = fast = head
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    
    orig = toRev = slow.next
    slow.next = None
    printLL(head)
    printLL(toRev)

    # reverse right part
    revHead = rev = reverse(toRev)

    while rev and head:
        if head.data != rev.data:
            print("Not Palindrome")
            # restore list
            slow.next = reverse(revHead)
            return False
        head = head.next
        rev = rev.next
    
    print("Palindrome")
    # restore list
    slow.next = reverse(revHead)
    return True

def printLL(start):
    temp = start
    while(temp.next):
        print(temp.data,end=" -> ")
        temp = temp.next
    print(temp.data)
        

head = Node(1)
temp = head
temp.next = Node(2)
temp = temp.next
temp.next = Node(3)
temp = temp.next
temp.next = Node(3)
temp = temp.next
temp.next = Node(2)
temp = temp.next
temp.next = Node(1)
temp = temp.next

printLL(head)
checkPalindrome(head)

temp.next = Node(3)
temp = temp.next
printLL(head)
checkPalindrome(head)