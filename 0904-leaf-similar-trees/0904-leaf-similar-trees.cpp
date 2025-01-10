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
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
            return;
        }
        solverRec(root->left, ans);
        solverRec(root->right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> v1;
        solverRec(root1,v1);
        vector<int> v2;
        
        solverRec(root2,v2);
        int n = v1.size();
        int m = v2.size();
        if(n!=m) return false;
        
        for(int i=0;i<n;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
        
    }
};