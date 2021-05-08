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
    bool compareNode(TreeNode* n1, TreeNode* n2) {
        if (n1->val == n2->val)
            return true;
        else 
            return false;
    }
    bool checkNode(TreeNode* n1, TreeNode* n2) {
        if (n1 && n2) {
            // cout << n1->val << " " << n2->val << endl;
            bool oneChildMatch = checkNode(n1->left, n2->right);
            bool secChildMatch = checkNode(n1->right, n2->left);
            bool parentMatch = compareNode(n1, n2);
            return oneChildMatch && secChildMatch && parentMatch;
        }
        else if (n1 == nullptr && n2 == nullptr) return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root) 
            return checkNode(root->left, root->right);
        return false;
    }
};
