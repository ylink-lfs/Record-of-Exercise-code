class Solution {
public:
    int minNumberInRotateArray(vector<int> v) {
        if(v.empty())
            return 0;
        if(v.size() == 1 || v[0] < v[v.size() - 1])
        {
            return v[0];
        }
        int l = 0, r = v.size() - 1, m;
        while(l < r - 1)
        {
            m = l + (r - l) / 2;
            if(v[m] == v[l] && v[m] == v[r])
            {
                int min_n = v[l];
                for(int i = l; i <= r; i++)
                {
                    if(v[i] < min_n)
                        min_n = v[i];
                }
                return min_n;
            }
            else if(v[m] < v[l] || v[m] == v[r])
            {
                r = m;
            }
            else if(v[m] > v[l] || v[m] == v[l])
            {
                l = m;
            }
        }
        return v[r];
    }
};
