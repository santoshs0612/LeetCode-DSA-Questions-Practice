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
    void solverRec(TreeNode* root, vector<int> &ans){
        if(root== NULL) return;
        solverRec(root->left,ans);
        ans.push_back(root->val);
        solverRec(root->right,ans);
    }
    void solverMorrishInorder(TreeNode* root, vector<int> &ans){

        while(root){
            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            else{

                TreeNode* prev = root->left;

                while(prev->right && prev->right!=root){
                    prev =prev->right;
                }

                if(prev->right==NULL){
                    prev->right = root;
                    root = root->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }

        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // recurssive 
        // vector<int> inorder;
        // solverRec(root,inorder);
        // return inorder;

        // morrish traversal with o(n) and space of O(1)

        vector<int> inorder;
        solverMorrishInorder(root,inorder);
        return inorder;        
    }
};