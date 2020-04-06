class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> curMinSeq, curMaxSeq;
        vector<int> cmpMaxMin(3);
        int res = nums[0];
        curMinSeq.push_back(nums[0]);
        curMaxSeq.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            cmpMaxMin[0] = nums[i];
            cmpMaxMin[1] = nums[i] * curMinSeq[i - 1];
            cmpMaxMin[2] = nums[i] * curMaxSeq[i - 1];
            sort(cmpMaxMin.begin(), cmpMaxMin.end());
            curMinSeq.push_back(cmpMaxMin[0]);
            curMaxSeq.push_back(cmpMaxMin[2]);
            res = max(res, cmpMaxMin[2]);
        }
        return res;
    }
};
