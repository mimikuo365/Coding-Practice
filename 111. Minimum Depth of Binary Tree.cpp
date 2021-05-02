class Solution {
public:

    void findMin(TreeNode* root, vector<int> &bfs, int height) {
        if (root != nullptr) {
            if (root->left == nullptr && root->right == nullptr)                                bfs.push_back(height);
            findMin(root->left, bfs, height+1);
            findMin(root->right, bfs, height+1);
        }
    }
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> bfs; 
        findMin(root, bfs, 1);
        return *min_element(bfs.begin(), bfs.end());
    }

};
