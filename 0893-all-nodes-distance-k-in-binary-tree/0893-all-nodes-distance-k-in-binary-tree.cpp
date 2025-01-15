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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        queue<TreeNode*> q;
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> mp;
        q.push(root);
        while(!q.empty()){

            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                mp[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                mp[temp->right]=temp;
            }
        }

        queue<pair<TreeNode*, int>> qq;

        qq.push({target,0});
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        int dist =0;
        while(!qq.empty()){
            auto it = qq.front();
            TreeNode* node = it.first;
            int dis = it.second;
            if(dis==k){
                ans.push_back(node->val);
            }
            qq.pop();

            if(node->left && !visited[node->left]){
                qq.push({node->left,dis+1});
                visited[node->left]=true;
            }
            if(node->right && !visited[node->right]){
                qq.push({node->right,dis+1});
                visited[node->right]=true;
            }
            if(mp.find(node)!=mp.end() && !visited[mp[node]]){

                qq.push({mp[node],dis+1});
                visited[mp[node]]=true;
            }

        }

        return ans;

        
    }
};