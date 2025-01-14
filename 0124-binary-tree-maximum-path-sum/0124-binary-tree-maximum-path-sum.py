# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    maxSum =-1e9
    def solverRec(self,root):
        if root ==None:
            return 0
        
        lSum = max(0,self.solverRec(root.left))
        
        rSum = max(0,self.solverRec(root.right))
        self.maxSum = max(self.maxSum, lSum+rSum+root.val)
        return max(lSum,rSum)+root.val
    def maxPathSum(self, root: Optional[TreeNode]) -> int:

        self.solverRec(root)
        return self.maxSum

        