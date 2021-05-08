class Solution {
public:
     int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        cout << haystack.size() << " " << needle.size() << endl;
        int len = (haystack.size() - needle.size());
        // cout << len << endl;
        for (int i = 0; (i <= len); i++) {
            // cout << 'h';
            if (haystack[i] == needle[0]) {
                bool match = true;
                for (int j = 1; j < needle.size() && match; j++) {
                    if (needle[j] != haystack[i+j]) match = false;
                }
                if (match) return i;
            }
        } 
        return -1;
    }
};
