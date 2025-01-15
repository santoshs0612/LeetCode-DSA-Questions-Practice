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
    void inorder(TreeNode* root,int &count){

        if(root==NULL) return;

        count++;

        inorder(root->left,count);
        inorder(root->right,count);
    }

    int solverRec(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        int lh = leftTreeHeight(root);
        int rh = rightTreeHeight(root);

        if(lh==rh){
            return (1<<lh)-1;
        }

        return 1+solverRec(root->left)+ solverRec(root->right);
    }

    int leftTreeHeight(TreeNode* root){

        int count =0;

        while(root){
            count++;
            root= root->left;
        }
        return count;
    }
    int rightTreeHeight(TreeNode* root){


        int count =0;

        while(root){
            count++;
            root= root->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {

        // int count=0;
        // inorder(root,count);
        // return count;

        return solverRec(root);
        
    }
};