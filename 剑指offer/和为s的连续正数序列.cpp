class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if(sum < 3)
            return res;
        int small = 1, big = 2;
        int cursum = small + big;
        vector<int> t;
        while(small < (sum + 1) / 2)
        {
            if(cursum == sum)
            {
                for(int i = small; i <= big; i++)
                    t.push_back(i);
                res.push_back(t);
                t.clear();
            }
            while(cursum > sum && small < (sum + 1) / 2)
            {
                cursum -= small;
                small++;
                if(cursum == sum)
                {
                    for(int i = small; i <= big; i++)
                        t.push_back(i);
                    res.push_back(t);
                    t.clear();
                }
            }
            big++;
            cursum += big;
        }
        return res;
    }
};
