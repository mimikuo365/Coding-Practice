class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        bool find = true;
        int i = 0;
        sort(strs.begin(),strs.end()); 
        // for (string s:strs)
        //     cout << s << ' ';
        for (i = 0; i < strs[0].size() && find; i = i) {
            char newChar = strs[0][i];
            cout << newChar << endl;
            for (int j = 1; j < strs.size() && find; j++) {
                string s = strs[j];
                if (i >= s.size()) find = false;
                else if (newChar != s[i]) find = false;
            }
            if (find) i++;
        }
        return strs[0].substr(0,i);
    }
};
