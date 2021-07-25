/* 
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Date: 2021-07-25
Algorithm: Two pointers, hash map
Note: First Attempt
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        int start = 0, end = 0, max_len = 0;
        unordered_map<char, int> char_index;          
        
        while(end < s.size()){
            if (char_index.find(s[end]) != char_index.end() && char_index[s[end]] >= start) 
                start = char_index[s[end]] + 1;
            
            char_index[s[end]] = end;
            
            if (end - start + 1 > max_len)
                max_len = end - start + 1;
            
            end += 1;
        }
        return max_len;
    }
};
