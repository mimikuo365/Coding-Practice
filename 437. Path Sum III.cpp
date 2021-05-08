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
    void printKPathUtil(TreeNode *root, vector<int>& path, int k, int &counter) {
        if (!root)
            return;
        path.push_back(root->val);
        printKPathUtil(root->left, path, k, counter);
        printKPathUtil(root->right, path, k, counter);

        int f = 0;
        for (int j=path.size()-1; j>=0; j--) {
            f += path[j];
            if (f == k)
                counter++;
                // printVector(path, j);
        }
        // cout << root->val << endl;
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int sum) {
        vector<int> path;
        int counter = 0;
        printKPathUtil(root, path, sum, counter);
        return counter;
    }

    void printVector(const vector<int>& v, int i) {
        for (int j=i; j<v.size(); j++)
            cout << v[j] << " ";
        cout << endl;
    }
};
