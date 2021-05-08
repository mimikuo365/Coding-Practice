class Solution {
public:
    bool checkDFS(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        
        else if (p != nullptr && q != nullptr) {
            cout << p->val << endl;
            if (p->val != q->val) return false;
            if (checkDFS(p->left, q->left))
                return checkDFS(p->right, q->right);
            return false;
        }
        else return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkDFS(p, q);
    }
};
