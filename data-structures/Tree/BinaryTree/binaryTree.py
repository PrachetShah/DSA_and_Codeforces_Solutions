from implementation import Node, Tree

def height(root):
    # TC: O(n), SC: O(height)
    def helper(root):
        if root is None:
            return 0
        return 1 + max(helper(root.left),helper(root.right))
    val = helper(root)
    return val

def diameter(root):
    # TC: O(n), SC: O(height)
    def helper(root):
        if root is None:
            return 0, 0
        op1, leftHeight = helper(root.left)
        op2, rightHeight = helper(root.right)
        op3 = leftHeight + rightHeight + 1

        dia = max(op1, max(op2, op3))
        height =  max(leftHeight, rightHeight)+1

        return dia, height
    
    dia, height = helper(root)
    print("Diameter of tree is:", dia, "with height:", height)
    return dia

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(3)
    root.right = Node(5)
    root.left.left = Node(7)
    root.left.right = Node(11)
    root.right.right = Node(20)
    root.right.left = Node(17)
    root.right.left.right = Node(6)

    tree = Tree()
    tree.levelOrderTraversal(root)
    h = height(root)
    print("Height of tree is ", h)
    diameter(root)