# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        if root==None:
            return []
        
        ans =list()
        q = []
        q.append(root)
        move =1
        while len(q)>0:

            qSize = len(q)
            temp =list()
            for i in range(0,qSize):
                node = q.pop(0)
                if node.left!=None:
                    q.append(node.left)
                
                if node.right!=None:
                    q.append(node.right)
                temp.append(node.val)
            
            if move%2==0:
                temp.reverse()
                ans.append(temp)
            else:
                ans.append(temp)
            move+=1
        return ans