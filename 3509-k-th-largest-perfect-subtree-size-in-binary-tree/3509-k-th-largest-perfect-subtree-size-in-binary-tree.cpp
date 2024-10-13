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
    // int kthLargestPerfectSubtree(TreeNode* root, int k) {
        
    // }
        int checkAndGetSize(TreeNode* root) {
        if (!root) return 0;

        int leftSize = checkAndGetSize(root->left);
        int rightSize = checkAndGetSize(root->right);
        
        // A perfect binary tree must have both left and right subtrees of equal size
        if (leftSize == rightSize) {
            return leftSize + rightSize + 1; // Include current node
        }
        return -1; // Not a perfect subtree
    }

    // Function to collect sizes of all perfect subtrees
    void collectPerfectSubtreeSizes(TreeNode* root, vector<int>& sizes) {
        if (!root) return;

        int size = checkAndGetSize(root);
        if (size != -1) { // If it's a perfect subtree
            sizes.push_back(size);
        }

        collectPerfectSubtreeSizes(root->left, sizes);
        collectPerfectSubtreeSizes(root->right, sizes);
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;
        collectPerfectSubtreeSizes(root, sizes);

        // If no perfect subtrees were found
        if (sizes.empty()) return -1;

        // Sort sizes in descending order to find the kth largest
        sort(sizes.rbegin(), sizes.rend());

        // If we have fewer than k perfect subtrees, return -1
        if (k > sizes.size()) {
            return -1;
        }

        // Return the kth largest size
        return sizes[k - 1];
    }
};