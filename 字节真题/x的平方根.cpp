class Solution {
public:
    int mySqrt(int x) {
        double xd = static_cast<double>(x);
        double left = 0, right = x, mid, eps = 1e-8;
        while(right - left > eps)
        {
            mid = left + (right - left) / 2;
            if(mid * mid < x)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return left + eps;
    }
};
