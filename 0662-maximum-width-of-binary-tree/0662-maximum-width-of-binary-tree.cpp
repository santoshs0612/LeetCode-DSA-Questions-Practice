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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        long long maxLen =0;
        long long first=1,second=1;
        while(!q.empty()){
            int qSize = q.size();
            maxLen = max((int)maxLen, qSize);
            long long mini = q.front().second;
            for(int i=0;i<qSize;i++){
                TreeNode* temp = q.front().first;
                long long index = q.front().second-mini;
                q.pop();
                if(i==0){
                    first = index;
                }
                if(i==qSize-1){
                    second = index;
                }
                if(temp->left!=NULL){
                    q.push({temp->left,2*index});
                }
                if(temp->right!=NULL){
                    q.push({temp->right,2*index+1});
                }
            }
            maxLen = max(maxLen,(second-first+1));
        }
        return (int)maxLen;
        
    }
};