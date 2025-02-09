from implementation import Tree, Node

def helperPre_In_Traversals(indexMap, preorder, preIndex, s, e):
    if s>e:
        return None
    root = Node(preorder[preIndex[0]])
    preIndex[0] += 1
    index = indexMap[preorder[preIndex[0]-1]]
    root.left = helperPre_In_Traversals(indexMap, preorder, preIndex, s, index-1)
    root.right = helperPre_In_Traversals(indexMap, preorder, preIndex, index+1, e)
    return root

def buildFromPreAndInTraversals(preorder, inorder):
    n = len(preorder)

    indexMap = {inorder[i]:i for i in range(n)}
    preIndex = [0]
    
    return helperPre_In_Traversals(indexMap, preorder, preIndex, 0, len(preorder)-1)

tree = Tree()
print("BUILDING TREE FROM PREORDER AND INORDER TRAVERSALS")
inorder = [3, 1, 4, 0, 5, 2]
preorder = [0, 1, 3, 4, 2, 5]
print("Inorder:", inorder, "\tPreorder:", preorder)
build = buildFromPreAndInTraversals(preorder, inorder)
print("\nPostorder Traversal After Building: ", end="")
tree.postorderTraversal(build)