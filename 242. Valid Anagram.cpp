class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map <char, int> allChar;
        for (char c: s) {
          if (allChar.find(c) != allChar.end())
            allChar[c]++;
          else allChar[c] = 1;
        }
        for (char c: t) {
          if (allChar.find(c) != allChar.end()) {
            allChar[c]--;
            if (allChar[c] == 0) allChar.erase(c);
          }
          else 
		return false;
        }
        if (allChar.empty()) return true;
	  return false;
    }
};
