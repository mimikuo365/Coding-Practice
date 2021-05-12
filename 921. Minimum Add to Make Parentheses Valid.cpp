// Time: 2021 May 12
// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Keywords: Parentheses, Stack

class Solution {
public:
    int minAddToMakeValid(string S) {
        int ctr = 0; 
        int sum = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') ctr++;
            else ctr--;
            
            // Check if ')' exists before '('
            if (ctr < 0) { 
                sum -= ctr;
                ctr = 0;
            }
        }
        return abs(ctr) + sum;
    }
};
