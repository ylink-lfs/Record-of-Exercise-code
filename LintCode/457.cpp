class Solution {
public:
    /*
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        int mid;
        int lower = 0;
        int upper = nums.size() - 1;
        while(lower <= upper)
        {
            mid = lower + (upper - lower) / 2;
            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                lower = mid + 1;
            else
                upper = mid - 1;
        }
        return -1;
    }
};
