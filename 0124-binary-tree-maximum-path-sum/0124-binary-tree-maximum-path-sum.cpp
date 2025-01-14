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
    int solverRec(TreeNode* root,int &maxSum){

        if(root==NULL){
            return 0;
        }

        int leftSum = max(0,solverRec(root->left,maxSum));
        int rightSum = max(0,solverRec(root->right, maxSum));

        maxSum = max(maxSum,leftSum+rightSum+root->val);
        return max(leftSum,rightSum)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {

        int maxSum =INT_MIN;
        solverRec(root,maxSum);
        return maxSum;
        
    }
};