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

def checkBalancedTree(root):
    def help(root):
        if root is None:
            return True, 0
        
        left, leftHeight = help(root.left)
        right, rightHeight = help(root.right)
        diff = abs(leftHeight-rightHeight)
        if left and right and diff <= 1:
            return True, 1+max(leftHeight, rightHeight)
        else:
            return False, 0
    return help(root)

def isIdentical(tree1, tree2):
    if tree1 == None and tree2==None:
        return True
    if tree1 == None and tree2 != None:
        return False
    if tree1 != None and tree2 == None:
        return False
    if tree1.val == tree2.val:
        return isIdentical(tree1.left, tree2.left) and isIdentical(tree1.right, tree2.right)
    else:
        return False

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(3)
    root.right = Node(5)
    root.left.left = Node(7)
    root.left.right = Node(11)
    root.right.right = Node(20)
    root.right.left = Node(17)
    root.right.left.right = Node(6)

    root2 = Node(1)
    root2.left = Node(3)
    root2.right = Node(5)
    # To make Tree Unbalanced
    # root.right.left.right.right = Node(102) 
    # root.right.left.right.right.right = Node(1020) 

    tree = Tree()
    tree.levelOrderTraversal(root)
    h = height(root)
    print("Height of tree is ", h)
    diameter(root)
    if checkBalancedTree(root)[0]:
        print("Balanced Tree")  
    else: 
        print("Not Balanced Tree")

    if isIdentical(root, root2):
        print("Trees are identical")
    else:
        print("Trees are not identical")
