// Dec 29 2022
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char c: s)
            if (m.find(c) == m.end())
                m[c] = 1;
            else m[c] += 1;
            
        int sum = 0;
        for (auto it: m) {
            sum += it.second / 2 * 2;
            if (sum % 2 == 0 && it.second % 2 == 1)
                sum += 1;            
        }   
        return sum; 
    }
};      
