from implementation import Tree, Node
from collections import defaultdict

def longestPathSum(root):
    '''
    What is the Maximum sum of longest path from root till leaf node
    '''
    maxSum = [0]
    sum = 0
    path = 0
    maxPath = [0]
    
    def helper(root, sum, maxSum, path, maxPath):
        if root is None:
            if path > maxPath[0]:
                maxPath[0] = path
                maxSum[0] = sum
            elif path == maxPath[0]:
                maxSum[0] = max(sum, maxSum[0])
            return
        sum = sum + root.data
        path = path + 1
        helper(root.left, sum, maxSum, path, maxPath)
        helper(root.right, sum, maxSum, path, maxPath)
    
    helper(root, sum, maxSum, path, maxPath)
    print(f"Max Sum of longest path({maxPath[0]}) of tree is: ",maxSum[0])

    # NOT OPTIMISED, AS IT STORES ALL THE PATHS, store only MAX ONE
    dictt = {}
    def solve(root, sum, path):
        if root is None:
            if path in dictt:
                dictt[path] = max(dictt[path], sum)
            else:
                dictt[path] = sum
            return
        sum += root.data
        path += 1
        solve(root.left, sum, path)
        solve(root.right, sum, path)
    solve(root, 0, 0)
    print(f"Max Sum of longest path with MAP: ", dictt)
    return maxSum[0]


def lowestCommonAncstorBinaryTree(root, n1, n2):
    '''
    ITS NOT THE MINIMUM, ITS THE LOWEST DESCENDANT
    When both left and right ans for a root are not NULL, it means it is the LCA
    The Lowest Common Ancestor (or LCA) is the lowest node in the tree that has both n1 and n2 as descendants. 
    In other words, the LCA of n1 and n2 is the shared ancestor of n1 and n2 that is located farthest from the root.

    One more thing here, is we should check whehther n1 an dn2 exists in tree as well, otherwise it will retur nthe first found
    instead of null
    '''
    def checkTree(root, n):
        if root == None:
            return False
        if root.data == n or checkTree(root.left, n) or checkTree(root.right, n):
            return True
        return False
    def solve(root):
        if root is None:
            return None
        if root.data == n1 or root.data==n2:
            # this means this is one of n1 or n2
            return root
        leftAns = solve(root.left)
        rightAns = solve(root.right)
        if (leftAns != None and rightAns != None):
            # this is the LCA of n1 and n2
            return root
        elif (leftAns != None and rightAns == None):
            return leftAns
        elif (leftAns == None and rightAns != None):
            return rightAns
        else:
            return None
    
    if checkTree(root, n1) and checkTree(root, n2):
        lca = solve(root) 
    else:
        lca = None
    print(f"Lowest(First) Common Ancestor of {n1} and {n2} is {lca.data if lca else 'NULL'}")

def KSumPaths(root, k):
    # Using Recursion
    count = [0]
    def solve(root, k, path:list):
        if root is None:
            return
        path.append(root.data)
        
        # left
        solve(root.left, k, path)
        # right
        solve(root.right, k, path)
        
        SUM = 0
        for i in range(len(path)-1, -1, -1):
            SUM += path[i]
            if SUM == k:
                print(path[i:])
                count[0] += 1
        path.pop(-1)
    print("Finding Total K Sum Paths, Paths are:")
    solve(root, k, [])
    print("Total Sum K Paths are:", count[0])
    pass

if __name__ == "__main__":
    '''
                1
        2               3
    4       5       6       7
                       8      9
                           120  100
    '''
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
    print("-"*60)
    longestPathSum(root)
    print("-"*60)
    lowestCommonAncstorBinaryTree(root, 4, 6)
    lowestCommonAncstorBinaryTree(root, 8, 100)
    lowestCommonAncstorBinaryTree(root, 8, 150)
    lowestCommonAncstorBinaryTree(root, 200, 150)
    print("-"*60)
    KSumPaths(root, 6)