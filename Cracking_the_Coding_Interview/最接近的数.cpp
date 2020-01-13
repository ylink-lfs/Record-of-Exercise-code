class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        int x_one_cnt = count_one(x);
        vector<int> res;
        for(int i = x - 1; ; i--)
        {
            int i_one_cnt = count_one(i);
            if(x_one_cnt == i_one_cnt)
            {
                res.push_back(i);
                break;
            }
        }
        for(int i = x + 1; ; i++)
        {
            int i_one_cnt = count_one(i);
            if(x_one_cnt == i_one_cnt)
            {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
    
    int count_one(int x)
    {
        int cnt = 0;
        while(x)
        {
            cnt++;
            x &= (x - 1);
        }
        return cnt;
    }
};
