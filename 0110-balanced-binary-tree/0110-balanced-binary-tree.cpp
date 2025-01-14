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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        return max(height(root->left),height(root->right))+1;
    }
    bool solverRec(TreeNode* root){
        if(root==NULL){
            return true;
        }
        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh-rh)>1){
            return false;
        }
        return solverRec(root->left) && solverRec(root->right);
    }
public:
    bool isBalanced(TreeNode* root) {

        return  solverRec(root);
        
    }
};