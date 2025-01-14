# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    dia =0
    def solverRec(self,root):
        if root==None:
            return 0
        
        lh = self.solverRec(root.left)
        rh = self.solverRec(root.right)

        self.dia = max(self.dia, lh+rh)

        return max(lh,rh)+1
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        
        self.solverRec(root)
        return self.dia
        
        