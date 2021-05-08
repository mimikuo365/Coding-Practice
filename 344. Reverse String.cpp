class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin = 0;
        int end = s.size()-1;
        while (begin < end) {
          char tmp = s[begin];
          s[begin] = s[end];
          s[end] = tmp;
          begin++; 
          end--;
        }
    }
};
