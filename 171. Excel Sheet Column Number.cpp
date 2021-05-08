class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int size = columnTitle.size()-1;
        for (int i = size; i >= 0; i--) {
            int n = (columnTitle[i] - 'A') + 1;
            int times = pow(26, (size-i));
            sum += n * times;
        }
        return sum;
    }
};
