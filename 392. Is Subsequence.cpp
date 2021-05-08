class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int i = 0, j = 0;
        bool isSub = false;
        while (!isSub && j < t.size()) {
          if (s[i] == t[j]) {
            i++; j++;
            if (i == s.size()) isSub = true;  
          }
          else j++;
        } 
        return isSub;
    }
};
