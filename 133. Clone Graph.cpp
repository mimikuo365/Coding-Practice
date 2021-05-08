class Solution {
public:
    Node* cloneGraph(Node* node) {
        vector<Node*> dp(101, nullptr);
        return makeGraph(node, dp);
    }
    Node* makeGraph(Node* node, vector<Node*>& dp) {
        if (node == nullptr) return nullptr;
        if (dp[node->val]) return dp[node->val];
        Node *newNode = new Node(node->val);
        dp[node->val] = newNode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            newNode->neighbors.push_back(makeGraph(node->neighbors[i], dp));
        }
        return newNode;
    } 
};
