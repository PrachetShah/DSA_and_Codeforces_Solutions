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
    
    def levelOrderTraversal(self, root):
        queue = []
        queue.append(root)
        queue.append(None)

        while len(queue) > 0:
            node = queue.pop(0)
            if node == None:
                if len(queue)>0:
                    queue.append(None)
                print()
            else:
                print(node.data, end=" ")
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

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
    
    def postorderTraversal(self, root):
        if root is None:
            return
        self.postorderTraversal(root.left)
        self.postorderTraversal(root.right)
        print(root.data, end = " ")

if __name__ == "__main__":
    root = Node(0)
    tree = Tree()
    # 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = tree.buildTree()
    print("\nInorder Traversal: ", end="")
    tree.inorderTraversal(root)

    print("\nPre order Traversal: ", end="")
    tree.preOrderTraversal(root)

    print("\nPost Order Traversal: ", end="")
    tree.postorderTraversal(root)

    print("\nLevel Order Traversal(BFS):")
    tree.levelOrderTraversal(root)