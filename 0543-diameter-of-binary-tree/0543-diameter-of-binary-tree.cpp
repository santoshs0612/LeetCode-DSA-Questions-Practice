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
    int solverRec(TreeNode* root, int &dia){
        if(root==NULL){
            return 0;
        }
        int lh = solverRec(root->left,dia);
        int rh = solverRec(root->right,dia);
        dia = max(dia, lh+rh);
        return max(lh,rh)+1; 
    
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia =0;
        solverRec(root,dia);
        return dia;
    }
};