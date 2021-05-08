class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"");
        for (int i = 0; i < n; i++) {
            int mod3 = (i+1) % 3;
            int mod5 = (i+1) % 5;
            if (mod3 == 0 && mod5 == 0) ans[i] = "FizzBuzz";
            else if (mod3 == 0) ans[i] = "Fizz";
            else if (mod5 == 0) ans[i] = "Buzz";
            else ans[i] = to_string(i+1);
        }
        return ans;
    }
};
