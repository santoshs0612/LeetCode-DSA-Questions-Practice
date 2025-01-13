/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* solverRec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL || root==p  || root==q){
            return root;
        }
        TreeNode* left= solverRec(root->left,p,q);
        TreeNode* right = solverRec(root->right,p,q);

        if(left==NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Use path method for evey node and store in array and compare it with element ---->   in second method logic is to return the node i.e if root->data==a/b the return root,    also if it is null return Null also one major condition if that for left and right  always check if left ==NULL return righ, same if right==NULL return left  or else case return root because you found the root node .


        return solverRec(root,p,q);
        
    }
};