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
int getHeight(TreeNode* root){
   if(root==NULL)return false;
   int lh=getHeight(root->left);
   int rh=getHeight(root->right);

   return 1+max(lh,rh);
}


    bool isBalanced(TreeNode* root) {

        // *****************approach_1  O(n2)****************
        if(root==NULL)return true;

        int lh=getHeight(root->left);
        int rh=getHeight(root->right);

        if(abs(lh-rh)>1)return false;//it should be <=

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(!left || !right)return false; //if any onr give you a false return false else true
        return true;
        
    }
};