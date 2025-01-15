/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* solverRec(unordered_map<int,int> &mp, int startIn, int endIn, vector<int> &preorder, int startPre, int endPre){


        if(startPre>endPre || startIn> endIn){
            return NULL;
        }
        int val = preorder[startPre];

        int index = mp[val];
        int leftNum = index -startIn;

        TreeNode* node = new TreeNode(val);
        node->left = solverRec(mp,startIn,index-1,preorder,startPre+1,startPre+leftNum);
        node->right = solverRec(mp,index+1,endIn, preorder,startPre+leftNum+1,endPre);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        return solverRec(mp,0,inorder.size()-1,preorder,0,preorder.size()-1);
        
    }
};