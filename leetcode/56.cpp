class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& v1, const vector<int>& v2) {
            return v1[0] < v2[0];
        };
        if(intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res{intervals[0]};
        for(int i = 1; i < intervals.size(); i++)
        {
            if(res.back()[1] < intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }

};
