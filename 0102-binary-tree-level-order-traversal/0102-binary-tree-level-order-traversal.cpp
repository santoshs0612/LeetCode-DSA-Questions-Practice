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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ans;
        if(root==NULL) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty()){
            auto it =q.front();
            int qsize = q.size();
            vector<int> ans1;
            int level =it.second;
            for(int i=0;i<qsize;i++){
                
                TreeNode* temp = q.front().first;
                if(temp!=NULL) ans1.push_back(temp->val);
                q.pop();
                if(temp!=NULL && temp->left){
                    q.push({temp->left,level+1});
                }if(temp!=NULL && temp->right){
                    q.push({temp->right,level+1});
                }
            }

            ans.push_back(ans1);

        }
        return ans;
    }
};