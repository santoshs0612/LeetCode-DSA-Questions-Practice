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
    void solverMorrishPostorder(TreeNode* root, vector<int> &ans){

        while(root!=NULL){

            if(root->left==NULL){
                ans.push_back(root->val);
                root = root->right;
            }

            else{

                TreeNode* prev= root->left;
                
                while(prev->right && prev->right!=root){
                    prev= prev->right;
                }

                if(prev->right==NULL){
                    prev->right= root;
                    root= root->left;
                }

                else{
                    prev->right=NULL;
                    ans.push_back(root->val);
                    root= root->right;
                }

            }
        }
    }
    void solverRec(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solverRec(root->left,ans);
        solverRec(root->right,ans);

    }
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorder;

        solverRec(root,preorder);
        return preorder;

    }
};