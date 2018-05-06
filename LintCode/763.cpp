class Solution {
public:
    /**
     * @param n: a decimal number
     * @param k: a Integer represent base-k
     * @return: a base-k number
     */
    string hexConversion(int n, int k) {
        string res;
        stack<int> istack;
        if(n == 0)
        {
            res += '0';
            return res;
        }
        while(n != 0)
        {
           istack.push(n % k);
           n /= k;
        }
        
        while(!istack.empty())
        {
            if(istack.top() < 10)
            {
                res += istack.top() + 48;
            }
            else
            {
                res += istack.top() + 55;    
            }
            istack.pop();
        }
        return res;
    }
};
