class Solution {
public:
    int firstUniqChar(string s) {
        int o = -1;
        vector<int> v(26,0);
        
        for(auto i : s)
            v[(char)i-'a']++;
        
        for(int i = 0; s[i]; i++)
        {
            if(v[(char)s[i] - 'a'] == 1)
            {
                o = i;
                break;
            }
        }
        return o;
    }
};
