class Node:
    def __init__(self, value):
        self.data = value
        self.next:Node = None

def reverse(head:Node) -> Node:
    prev = None
    curr = head
    while curr:
        temp = curr.next
        curr.next = prev
        prev = curr
        curr = temp
    return prev

def addTwoLL(num1:Node, num2:Node) -> Node:
    l1 = reverse(num1)
    l2 = reverse(num2)
    carry = 0
    ansHead = ans = Node(0)
    while(l1 or l2 or carry):
        digit1 = l1.data if l1 is not None else 0
        digit2 = l2.data if l2 is not None else 0
        sum = digit1 + digit2 + carry

        value = sum%10
        carry = sum//10

        ans.next = Node(value)
        ans = ans.next

        if l1:
            l1 = l1.next
        if l2:
            l2 = l2.next
    return reverse(ansHead.next)

def printLL(head:Node):
    temp = head
    while temp.next:
        print(temp.data, end=" -> ")
        temp = temp.next
    print(temp.data)

num1 = Node(4)
num1.next = Node(5)

num2 = Node(3)
num2.next = Node(4)
num2.next.next = Node(5)

printLL(num1)
print("+")
printLL(num2)
print("=")
sum = addTwoLL(num1, num2)
printLL(sum)