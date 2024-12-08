# Clone a linked list with random pointer
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
        self.random = None
    

def clone_linked_list(head:Node):
    if head is None:
        return head
    
    # create modified list for cloning
    curr = head
    while curr:
        newNode = Node(curr.data)
        newNode.next = curr.next
        curr.next = newNode
        curr = newNode.next
    
    # clone random nodes
    curr = head
    while curr:
        if curr.random is not None:
            curr.next.random = curr.random.next
        curr = curr.next.next
    
    # split lists
    curr = head
    cloneHead = clone = curr.next
    while clone.next:
        curr.next = curr.next.next
        clone.next = clone.next.next

        curr = curr.next
        clone = clone.next
    
    return cloneHead



# Function to print the linked list
def print_list(head):
    while head is not None:
        print(f"{head.data}(", end="")
        if head.random:
            print(f"{head.random.data})", end="")
        else:
            print("null)", end="")
        
        if head.next is not None:
            print(" -> ", end="")
        head = head.next
    print()

if __name__ == "__main__":
    # Creating a linked list with random pointer
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.next.next.next = Node(4)
    head.next.next.next.next = Node(5)
    head.random = head.next.next
    head.next.random = head
    head.next.next.random = head.next.next.next.next
    head.next.next.next.random = head.next.next
    head.next.next.next.next.random = head.next
    
    # Print the original list
    print("Original linked list:")
    print_list(head)
    
    # Function call
    cloned_list = clone_linked_list(head)
    
    print("Cloned linked list:")
    print_list(cloned_list)