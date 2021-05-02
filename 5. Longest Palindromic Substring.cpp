class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = findLen(s, i, i);
            int len2 = findLen(s, i, i+1);
            int maxL = max(len1, len2);
            if (maxL > end - start) {
                start = i - (maxL-1) / 2; 
                end = i + maxL / 2;
            }
        }
        return s.substr(start, end-start+1);
    }
    int findLen(string s, int i, int j) {
        int len = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    }
};
