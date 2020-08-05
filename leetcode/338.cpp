class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        int exponent = 0;
        for(int i = 1; i <= num; i++)
        {
            if(i == 1)
            {
                res.push_back(1);
                continue;
            }
            if((i & (i - 1)) == 0)
            {
                res.push_back(1);
                exponent = i;
            }
            else
            {
                int t = i - exponent;
                res.push_back(res[t] + 1);
            }
        }
        return res;
    }
};
