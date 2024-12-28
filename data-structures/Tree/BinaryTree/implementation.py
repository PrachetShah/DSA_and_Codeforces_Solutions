class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Tree:
    def buildTree(self):
        data = int(input("Enter Data: "))
        root = Node(data)
        if data == -1:
            return
        
        print(f"Enter Data for Left of {data},", end="")
        root.left = self.buildTree()
        print(f"Enter Data for right of {data},", end="")
        root.right = self.buildTree()
        return root

    def preOrderTraversal(self, root):
        if root is None:
            return
        print(root.data, end = " ")
        self.preOrderTraversal(root.left)
        self.preOrderTraversal(root.right)

    def inorderTraversal(self, root):
        if root is None:
            return
        self.inorderTraversal(root.left)
        print(root.data, end = " ")
        self.inorderTraversal(root.right)

root = Node(0)
tree = Tree()
# 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
root = tree.buildTree()
print("\nPre order Traversal: ", end="")
tree.preOrderTraversal(root)

print("\nInorder Traversal: ", end="")
tree.inorderTraversal(root)