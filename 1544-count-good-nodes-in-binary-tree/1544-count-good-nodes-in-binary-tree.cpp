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
    void solverRec(TreeNode* root, int val, int &count){

        if(root==NULL){
            return;
        }

        // check for the value max 

        if(root->val >= val){
            count+=1;
            val =root->val;
        }
        solverRec(root->left,val,count);
        solverRec(root->right, val, count);
    }
public:
    int goodNodes(TreeNode* root) {

        int count =0;

        solverRec(root,root->val,count);

        return count;
        
    }
};