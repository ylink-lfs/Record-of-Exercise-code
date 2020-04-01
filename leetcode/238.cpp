class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++)
        {
            result[i] *= (result[i - 1] * nums[i - 1]);
        }
        int current_product_by_right = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            result[i] *= current_product_by_right;
            current_product_by_right *= nums[i];
        }
        return result;
    }
};
