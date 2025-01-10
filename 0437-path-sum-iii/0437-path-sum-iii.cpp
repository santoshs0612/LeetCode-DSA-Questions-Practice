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
    void solverRec(TreeNode *root ,long long sum, int target, int &count,unordered_map<long long,int> &mp){

        if(root==NULL){
            return;
        }

        sum = sum+root->val;

        if(sum == target){
            count++;
        }
        if(mp.find(sum-target)!=mp.end()){
            count+= mp[sum-target];
        }
        
        mp[sum]++;
        solverRec(root->left, sum,target, count,mp);
        solverRec(root->right, sum, target, count,mp);
        mp[sum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {

        int count=0;
        unordered_map<long long,int> mp;
        solverRec(root,0,targetSum,count,mp);

        return count;
        
    }
};