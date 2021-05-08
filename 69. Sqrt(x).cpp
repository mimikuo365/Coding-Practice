class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1;
        long int beg = 0, end = x;
        while(beg <= end) {
            long int mid = beg + (end - beg) / 2;
            
            if (mid * mid == x) 
                return mid;
            else if (((mid - 1) * (mid - 1) < x && x < mid * mid)) 
                return mid - 1;
            else if (mid * mid > x) 
                end = mid - 1;
            else 
                beg = mid + 1;
        }
        return 0;
    }
};
