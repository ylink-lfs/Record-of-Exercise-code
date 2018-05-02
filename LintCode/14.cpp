class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        int mid;
        while(lower < upper)
        {
            mid = lower + (upper - lower) / 2;
            if(nums[mid] >= target)
            {
                upper = mid;
            }
            else
            {
                lower = mid + 1;
            }
        }
        if(nums[lower] == target)
        {
            return lower;
        }
        else
        {
            return -1;
        }
    }
};
