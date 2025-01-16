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
    TreeNode* helper(TreeNode* root){

        if(root->left==NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }

        TreeNode* leftNode = root->right;
        TreeNode* leftMax = rightMax(root->left);
        leftMax->right = leftNode;
        return root->left;
    }
    TreeNode* rightMax(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return rightMax(root->right);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if(root==NULL) return root;
        // if(root->val==key){
        //     return helper(root);
        // }
        // TreeNode* temp= root;
        // while(root){

        //     if(root->val > key){

        //         if(root->left && root->left->val == key){
        //             root->left= helper(root->left);
        //             break;
        //         }else{
        //             root= root->left;
        //         }
        //     }else{
        //         if(root->right && root->right->val == key){
        //             root->right = helper(root->right);
        //             break;
        //         }else{
        //             root= root->right;
        //         }
        //     }
        // }
        // return temp;


        if(root!=NULL){

            if(key < root->val){

                root->left = deleteNode(root->left,key);
            }else if(key > root->val){
                root->right = deleteNode(root->right,key);
            }
            else{

                if(root->right ==NULL && root->left ==NULL){
                    return NULL;
                }else if( root->right ==NULL || root->left ==NULL){

                    return root->right!=NULL? root->right:root->left;
                }
                else{
                    TreeNode* temp = root->left;
                    while(temp->right!=NULL){
                        temp = temp ->right;
                    }
                    root->val = temp->val;
                    root->left = deleteNode(root->left,temp->val);
                }



            }

        }
        return root;
    }
};