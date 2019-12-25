class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return partition(0, nums.size() - 1, nums.size() - k, nums);
    }
    
    //[left, right] in nums
    int partition(const int left, const int right, const int k, vector<int>& nums)
    {
        
        int l = left, r = right, pivot = nums[left];
        while(l < r)
        {
            while(l < r && nums[r] >= pivot)
                r--;
            if(l < r)
                nums[l++] = nums[r];
            while(l < r && nums[l] < pivot)
                l++;
            if(l < r)
                nums[r--] = nums[l];
        }
        nums[l] = pivot;
        if(l == k)
        {
            return nums[l];
        }
        else if(l < k)
        {
            return partition(l + 1, right, k, nums);
        }
        else
        {
            return partition(left, l - 1, k, nums);
        }
    }
};
