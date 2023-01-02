class Solution {
public:
    bool detectCapitalUse(string word) {
        bool isCap = false;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            bool curCap = c - 'a' < 0;
            if (!isCap && curCap && i != 0)
                return false;
            else if (isCap && !curCap && i != 1) // check if it is not second
                return false;
            isCap = curCap;
        }
        return true;
    }
};
