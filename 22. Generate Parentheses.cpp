class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0)
            ans.push_back("");
        else {
            for (int c = 0; c < n; c++) {
                for (string i: generateParenthesis(c)) {
                    for (string j: generateParenthesis(n-c-1)) {
                        ans.push_back("(" + i + ")" + j);
                    }
                }
            }
        }
        return ans;
    }
};
