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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){//tree doesnot have any zigzag traversal
            return res;
        }
        queue<TreeNode*>nodesQueue;
        nodesQueue.push(root);
        bool leftToRight=true;//it means left to right

        while(!nodesQueue.empty()){
            //takes all node of that level
            int size=nodesQueue.size();
            vector<int>row(size);
            for(int i=0;i<size;i++){
                TreeNode* node=nodesQueue.front();
                nodesQueue.pop();

                // find position to fill nodes valsue
                int index=(leftToRight)?i:(size-1-i);

                row[index]=node->val;
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }

            }
            // after thi slevel
            leftToRight=!leftToRight;
            res.push_back(row);
        }
        return res;
    }
};