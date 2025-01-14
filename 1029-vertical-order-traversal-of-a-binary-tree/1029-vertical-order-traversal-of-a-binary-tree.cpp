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
    void solverRec(TreeNode *root,map<int,vector<int>> &mp,int pos){
        if(root==NULL){
            return ;
        }
        mp[pos].push_back(root->val);
        solverRec(root->left,mp,pos-1);
        solverRec(root->right,mp,pos+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // vector<vector<int>> ans;
        // map<int,vector<int>> mp;
        // solverRec(root,mp,0);
        // for(auto it:mp){
        //     vector<int> temp = it.second;
        //     // for(int i=0;i<temp.size();i++){
        //     //     cout<<temp[i]<<" ";
        //     // }
        //     sort(temp.begin(),temp.end());
        //     ans.push_back(temp);
        //     // cout<<endl;
        // }
        // order matter so another method 
        if(root==NULL){
            return {};
        }
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int x = it.second.first;
            int y = it.second.second;

            mp[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                q.push({temp->right,{x+1,y+1}});
            }
        }

        for(auto it:mp){
            vector<int> temp;
            for(auto v:it.second){
                temp.insert(temp.end(),v.second.begin(),v.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};