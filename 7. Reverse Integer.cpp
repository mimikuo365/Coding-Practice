class Solution {
public:
    int reverse(int x) {
        int re = 0;
        while(x != 0) {
            re = re * 10 + (x % 10);
            x = x / 10;
            if (x != 0) {
                if (re < (INT_MIN / 10)) return 0;
                else if (re > (INT_MAX / 10)) return 0;
            }
        }
        return re;
    }
};
