class Solution {
public:
    bool Find(int tar, vector<vector<int> > v) {
        if(v.empty() || v[0].empty())
            return false;
        else
        {
            int x = v.size() - 1, y = 0;
            while(x < v.size() && y < v[0].size())
            {
                if(v[x][y] == tar)
                {
                    return true;
                }
                else if(v[x][y] < tar)
                {
                    y++;
                }
                else
                {
                    x--;
                }
            }
            return false;
        }
    }
};
