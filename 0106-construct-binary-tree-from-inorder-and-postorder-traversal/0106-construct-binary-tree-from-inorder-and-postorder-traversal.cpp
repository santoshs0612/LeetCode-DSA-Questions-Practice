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
    TreeNode* solverRec(unordered_map<int,int> &mp,int inStart, int inEnd, vector<int> &postorder, int poStart, int poEnd){
        if(poEnd<poStart || inStart>inEnd){
            return NULL;
        }

        int ind = mp[postorder[poEnd]];
        int numleft = ind - inStart;

        TreeNode* node = new TreeNode(postorder[poEnd]);

        node->left = solverRec(mp,inStart,ind-1,postorder,poStart,poStart+numleft-1);
        node->right = solverRec(mp,ind+1,inEnd,postorder,poStart+numleft,poEnd-1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++){

            mp[inorder[i]]=i;
        }

        return solverRec(mp,0,inorder.size()-1,postorder, 0,postorder.size()-1);

        
    }
};