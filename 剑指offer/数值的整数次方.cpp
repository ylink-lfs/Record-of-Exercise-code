class Solution {
public:
    const double eps = 1e-8;
    double Power(double base, int exponent) {
        if(exponent == 0)
        {
            base = 1.0;
        }
        else if(fabs(base) >= eps)
        {
            
            double b = base;
            if(exponent > 0)
            {
                for(int i = 1; i < exponent; i++)
                {
                    base *= b;
                }
            }
            else
            {
                for(int i = 0; i >= exponent; i--)
                {
                    base /= b;
                }
            }
            
        }
        return base;
    }
};
