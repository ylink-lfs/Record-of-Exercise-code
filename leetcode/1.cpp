class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp.insert(make_pair(nums[0], 0));
        vector<int> result;
        for(int i = 1; i < nums.size(); i++)
        {
            int component_num = target - nums[i];
            if(mp.find(component_num) != mp.end())
            {
                result.push_back(mp.at(component_num));
                result.push_back(i);
                break;
            }
            else
            {
                mp.insert(make_pair(nums[i], i));
            }
        }
        return result;
    }
};
