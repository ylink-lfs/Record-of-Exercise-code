class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums.back() < 0 || nums.front() > 0) 
            return {};
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int fix_num = nums[i];
            if(fix_num > 0)
            {
                break;
            }
            else if(i > 0 && fix_num == nums[i - 1])
            {
                continue;
            }
            else
            {
                int target = -fix_num;
                int j = i + 1, k = nums.size() - 1;
                while(j < k)
                {
                    if(nums[j] + nums[k] < target)
                        j++;
                    else if(nums[j] + nums[k] > target)
                        k--;
                    else
                    {
                        res.insert({nums[i], nums[j], nums[k]});
                        while(j < k && nums[j] == nums[j + 1])
                            j++;
                        while(j < k && nums[k] == nums[k - 1])
                            k--;
                        j++;
                        k--;
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
