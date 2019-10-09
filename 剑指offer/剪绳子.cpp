class Solution {
public:
    int cutRope(int n) {
        int sum = 1;
        while(n > 5)
        {
            n -= 3;
            sum *= 3;
        }
        if(n == 5)
            sum *= 6;
        else if(n == 4)
            sum *= 4;
        else if(n == 3)
            sum *= 2;
        else if(n == 2)
            return 1;
        else
            return 0;
        return sum;
    }
};
