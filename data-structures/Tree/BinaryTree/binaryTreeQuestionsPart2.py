from implementation import Tree, Node
from collections import defaultdict

def zigZagTraversal(root):
    queue = []
    queue.append([root])
    isEven = 0
    ans = []
    while queue:
        curr = queue.pop()
        nextDepth = []
        for node in curr:
            if node.left:
                nextDepth.append(node.left)
            if node.right:
                nextDepth.append(node.right)
        if isEven%2==0:
            ans.append([node.data for node in curr])
        else:
            ans.append([node.data for node in curr[::-1]])
        isEven = not isEven
        if len(nextDepth):
            queue.append(nextDepth)
    print("Zig Zag Traversal:\t\t", ans)

def boundaryTraversal(root):
    ans = [root.data]

    def traverseLeft(root: Node):
        if root is None or (root.left is None and root.right is None):
            return
        ans.append(root.data)
        if root.left:
            traverseLeft(root.left)
        else:
            traverseLeft(root.right)

    def leafTraversal(root: Node):
        if root is None:
            return
        if root.left is None and root.right is None:
            ans.append(root.data)
        if root.left:
            leafTraversal(root.left)
        if root.right:
            leafTraversal(root.right)
    
    def rightTraversal(root: Node):
        if root is None or (root.left is None and root.right is None):
            return
        if root.right:
            rightTraversal(root.right)
        else:
            rightTraversal(root.left)
        ans.append(root.data)
    
    print("Boundary traversal: \t", end=" ")
    # traverse left
    if root.left:
        traverseLeft(root.left, ans)
    
    # traverse leaf: left subtree and right subtree
    leafTraversal(root.left)
    leafTraversal(root.right)

    # travese right
    rightTraversal(root.right)
    print(ans)


def verticalTraversal(root):
    map = defaultdict(list)
    def helper(root, index, map):
        if root is None:
            return
        map[index].append(root.data)
        if root.left:
            helper(root.left, index-1, map)
        if root.right:
            helper(root.right, index+1, map)
    helper(root, 0, map)
    traversal = []
    
    print(sorted(map.items()))
    for key in sorted(map):
        traversal.extend(map[key])
    print("Vertical Level Traversal:\t", traversal)

if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right = Node(3)
    root.right.left = Node(6)
    root.right.right = Node(7)
    root.right.left.right = Node(8)
    root.right.right.right = Node(9)
    root.right.right.right.right = Node(100)
    root.right.right.right.left = Node(120)

    tree = Tree()
    tree.levelOrderTraversal(root)

    zigZagTraversal(root)
    boundaryTraversal(root)
    verticalTraversal(root)