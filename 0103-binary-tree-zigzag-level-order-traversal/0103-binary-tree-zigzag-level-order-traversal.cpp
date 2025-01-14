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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        int move=1;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){
            int qSize = q.size();
            vector<int> temp;
            for(int i=0;i<qSize;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                temp.push_back(node->val);
            }
            if(move%2==0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            else{
                ans.push_back(temp);
            }
            move++;
        }
        return ans;
    }
};