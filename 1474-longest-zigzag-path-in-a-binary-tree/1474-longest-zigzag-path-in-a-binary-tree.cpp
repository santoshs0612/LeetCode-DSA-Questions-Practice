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
    void maxPath(TreeNode* root, string dir,int len){
        if(root==NULL){
            return;
        }
        maxLen = max(maxLen,len);
        if(dir == "left"){
            maxPath(root->left,"right",len+1);
            maxPath(root->right,"left",1);
        }
        if(dir == "right"){
            maxPath(root->right,"left",len+1);
            maxPath(root->left,"right",1);
        }
    }
public:
    int maxLen=0;
    int longestZigZag(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        maxPath(root,"left",0);
        maxPath(root,"right",0);
        return maxLen;
    }
};