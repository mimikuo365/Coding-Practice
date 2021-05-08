class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            // cout << n << " " << (n % 3) << endl;
            if ((n % 3) != 0) return false;
            else n = n / 3;
        }
        return true;
    }
};
