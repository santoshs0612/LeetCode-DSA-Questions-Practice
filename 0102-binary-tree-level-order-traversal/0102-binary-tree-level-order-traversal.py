# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        ans = list()
        if root==None:
            return []
        q = []
        q.append(root)

        while len(q) > 0:
            length = len(q)
            temp = []
            for i in range(0,length):
                node = q.pop(0)
                if(node==None):
                    break
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                temp.append(node.val)
            ans.append(temp)

        return ans
        