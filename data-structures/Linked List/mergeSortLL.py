class Node:
    def __init__(self, value) -> None:
        self.data:int = value
        self.next:Node = None
    
def printLL(start):
    temp = start
    while(temp.next):
        print(temp.data,end=" -> ")
        temp = temp.next
    print(temp.data)
        

def findMiddle(head):
    if head == None:
        return head
    slow = fast = head
    while(fast.next and fast.next.next):
        slow = slow.next
        fast = fast.next.next
    return slow

def merge(left, right):
    if left is None:
        return right
    if right is None:
        return left

    result = Node(-1)
    head = result

    while left and right:
        if left.data < right.data:
            result.next = left
            left = left.next
        else:
            result.next = right
            right = right.next
        result = result.next
    
    if left:
        result.next = left
    if right:
        result.next = right
    
    return head.next

def mergeSort(head):
    if head is None or head.next is None:
        return head
    
    middle = findMiddle(head)
    right = middle.next
    middle.next = None
    left = head
    
    leftSort = mergeSort(left)
    rightSort = mergeSort(right)
    sortedList = merge(leftSort, rightSort)
    return sortedList


head = Node(7) 
temp = head 
temp.next = Node(10)
temp = temp.next
temp.next = Node(5)
temp = temp.next
temp.next = Node(20)
temp = temp.next
temp.next = Node(3)
temp = temp.next
temp.next = Node(2)
temp = temp.next

printLL(head)
sortedList = mergeSort(head)
printLL(sortedList)
