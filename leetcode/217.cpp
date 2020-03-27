class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(const auto n : nums)
        {
            if(mp.find(n) == mp.end())
                mp[n] = 1;
            else
                return true;
        }
        return false;
    }
};
