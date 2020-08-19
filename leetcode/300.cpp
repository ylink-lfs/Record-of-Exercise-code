class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        int mx = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i] && (dp[j] + 1 > dp[i]))
                {
                    dp[i] = dp[j] + 1;
                    mx = max(mx, dp[i]);
                }
            }
        }
        return mx;
    }
};
