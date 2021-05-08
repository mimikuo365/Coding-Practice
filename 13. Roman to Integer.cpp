class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbol = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        int val = symbol[s.back()];
        int i = s.size()-2;
 	    while (i >= 0) {
	        if (symbol[s[i]] < symbol[s[i+1]]) 
                val -= symbol[s[i]];
	        else
                val += symbol[s[i]];
            i--;
 	    }
	  return val;
    }
};
