class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        vector<bool> dp(nums.size());
        dp[0] = true;
        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(dp[j] && j + nums[j] >= i)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
