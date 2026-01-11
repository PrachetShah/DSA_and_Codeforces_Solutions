# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        minVal, maxVal = float('-inf'), float('inf')
        def solve(root, minVal, maxVal):
            if root is None:
                return True
            if root.val <= minVal or root.val >= maxVal:
                return False
            return solve(root.left, minVal, root.val) and solve(root.right, root.val, maxVal)
        return solve(root, minVal, maxVal) 