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
    bool checkTree(TreeNode* root) {
        int sum=0;
        if(root==NULL ||(root->right==NULL && root->left==NULL))return 1;
        if(root->left!=NULL)sum+=root->left->val;
        if(root->right!=NULL)sum+=root->right->val;
        return(root->val==sum && checkTree(root->left) && checkTree(root->right));

        
    }
};