class Solution {
public:
    deque<deque<bool>> color;
    deque<deque<bool>> counted;
    int movingCount(int k, int m, int n)
    {
        color.clear();
        color.resize(m);
        counted.clear();
        counted.resize(m);
        for(int i = 0; i < m; i++)
        {
            color[i].resize(n);
            counted[i].resize(n);
            fill(color[i].begin(), color[i].end(), true);
            fill(counted[i].begin(), counted[i].end(), false);
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                string s(to_string(i));
                s += to_string(j);
                int sum = 0;
                for(auto e : s)
                {
                    sum += e - '0';
                }
                if(sum > k)
                {
                    color[i][j] = false;
                }
            }
        }
        int cnt = 0;
        count_block(0, 0, m, n, cnt);
        return cnt;
    }
    void count_block(const int curm, const int curn, const int m, const int n, int& cnt)
    {
        if(curm < 0 || curn < 0 || curm >= m || curn >= n)
        {
            return;
        }
        else if(counted[curm][curn])
        {
            return;
        }
        else if(!color[curm][curn])
        {
            return;
        }
        else
        {
            cnt++;
            counted[curm][curn] = true;
            count_block(curm - 1, curn, m, n, cnt);
            count_block(curm + 1, curn, m, n, cnt);
            count_block(curm, curn - 1, m, n, cnt);
            count_block(curm, curn + 1, m, n, cnt);
        }
    }
    
};
