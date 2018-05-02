class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        double lower = 1;
        double upper = x - 1;
        double mid;
        for(int i = 0; i < 500; i++)
        {
            mid = lower + (upper - lower) / 2;
            if(mid * mid < x)
            {
                lower = mid + 1;
            }
            else if (mid * mid > x)
            {
                upper = mid  -1;
            }
        }
        return int(mid);
    }
};
