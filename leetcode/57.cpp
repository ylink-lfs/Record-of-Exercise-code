class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int cur = 0;
        vector<vector<int>> res;
        while(cur < intervals.size() && intervals[cur][1] < newInterval[0])
        {
            res.push_back(intervals[cur]);
            cur++;
        }
        while(cur < intervals.size() && intervals[cur][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[cur][0], newInterval[0]);
            newInterval[1] = max(intervals[cur][1], newInterval[1]);
            cur++;
        }
        res.push_back(newInterval);
        while(cur < intervals.size())
            res.push_back(intervals[cur++]);
        return res;
    }
};
