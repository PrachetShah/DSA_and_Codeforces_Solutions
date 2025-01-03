from implementation import Tree, Node
from collections import defaultdict

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
    print("Vertical Level Traversal:", traversal)

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

    tree = Tree()
    tree.levelOrderTraversal(root)

    verticalTraversal(root)