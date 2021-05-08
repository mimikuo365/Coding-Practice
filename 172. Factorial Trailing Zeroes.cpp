class Solution {
public:
    int trailingZeroes(int n) {
        int mod2 = 0, twiceTimes = 2;
        int mod5 = 0, fifthTimes = 5;
        int tmp = n;
        while (tmp / twiceTimes > 0) {
            mod2 += tmp / twiceTimes;
            twiceTimes *= 2;
        }
        while (n / fifthTimes > 0) {
            mod5 += tmp / fifthTimes;
            fifthTimes *= 5;
        }
        return min(mod2, mod5);
    }
};
