class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //array contain at least 1 number
        if(nums.size() == 1)
            return nums[0];
        int curSum = nums[0];
        int maxSum = curSum;
        for(int i = 1; i < nums.size(); i++)
        {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(curSum, maxSum);
        }
        return maxSum;
    }
};
