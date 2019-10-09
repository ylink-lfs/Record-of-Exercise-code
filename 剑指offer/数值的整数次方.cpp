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
                base = positive_power(base, exponent);
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
    
    double positive_power(const double base, const int exponent)
    {
        if(exponent == 0)
        {
            return 1;
        }
        else if(exponent == 1)
        {
            return base;
        }
        else if(exponent % 2 == 1)
        {
            return base * positive_power(base, exponent - 1);
        }
        else
        {
            double half_res = positive_power(base, exponent / 2);
            return half_res * half_res; 
        }
    }
};
