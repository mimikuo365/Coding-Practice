class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> all_c;
        for (char c : s) {
            if (('a' <= c && c <= 'z') || 
                ('A' <= c && c <= 'Z') || 
                ('0' <= c && c <= '9')) {
                all_c.push_back(tolower(c));
                // cout << c;                
            }
        }
        for (int i = 0; i < all_c.size() / 2; i++) {
            if (all_c[i] != all_c[all_c.size() - 1 - i])
                return false;
        }
        return true;
    }
};
