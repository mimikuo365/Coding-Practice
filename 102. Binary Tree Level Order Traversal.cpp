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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> tr;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> t = q.front();
            q.pop();
            if (tr.size() > t.second)
                tr[t.second].push_back(t.first->val);
            else
                tr.push_back({t.first->val});
            if (t.first->left) 
                q.push(make_pair(t.first->left, t.second+1));
            if (t.first->right) 
                q.push(make_pair(t.first->right, t.second+1));
        }
        return tr;
    }
};
