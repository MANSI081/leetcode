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
// int getHeight(TreeNode* root){
//    if(root==NULL)return false;
//    int lh=getHeight(root->left);
//    int rh=getHeight(root->right);

//    return 1+max(lh,rh);
// }


//     bool isBalanced(TreeNode* root) {

//         // *****************approach_1  O(n2)****************
//         if(root==NULL)return true;


//         //here in next approach we remove these lh nad rh by which complexity become O(n)
//         int lh=getHeight(root->left);
//         int rh=getHeight(root->right);

//         if(abs(lh-rh)>1)return false;//it should be <=

//         bool left=isBalanced(root->left);
//         bool right=isBalanced(root->right);

//         if(!left || !right)return false; //if any onr give you a false return false else true
//         return true;
        
//     }

    // ************************************approach2 complexity O(n)************


    bool isBalanced(TreeNode* root) {
        return dfsHeight(root)!=-1;///redturn -1 then the balanced binary tree nahi tojh unbalnaced binary tree
        //  Check if the tree's height difference
        // between subtrees is less than 2
        // If not, return false; otherwise, return true

    }
int dfsHeight(TreeNode* root){
       if(root==NULL)return 0;
       int lh=dfsHeight(root->left);
       
       if(lh==-1 )return -1;
       int rh=dfsHeight(root->right);
       
       if(rh==-1)return -1;

   

       if(abs(lh-rh)>1)return -1;

       return max(lh,rh)+1;
       
    }
};