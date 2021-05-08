class Solution {
public:
    string removeDuplicates(string S) {
        string newS = "*";
        for (int i = 0; i < S.size(); i++) {
            if (newS[newS.size()-1] == S[i]) newS.pop_back();
            else newS.push_back(S[i]);
        }
        newS.erase(0, 1);
        return newS;
    }
};
