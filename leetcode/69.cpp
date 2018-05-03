class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        double lower = 1;
        double upper = x;
        double mid;
        while(upper - lower >= 1e-10)
        {
            mid = lower + (upper - lower) / 2;
            if(mid * mid < x)
            {
                lower = mid;
            }
            else
            {
                upper = mid;
            }
        }
        return int(upper);
    }
};
