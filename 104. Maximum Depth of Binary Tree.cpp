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
    int countHeight(TreeNode *node) {
        if (!node) return 0;
        else if (!node->left && !node->right) return 1;
        else return max(countHeight(node->left), countHeight(node->right)) + 1; 
    }
    int maxDepth(TreeNode* root) {
        return countHeight(root);
    }
};
