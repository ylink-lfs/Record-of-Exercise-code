//tough question...
class Solution {
public:
    /*
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
     double min(double a, double b)
     {
         return a > b ? b : a;
     }
     
     
     double getSum(vector<int>& nums)
     {
         double sum = 0;
         for(auto it = nums.begin(); it < nums.end(); it++)
            sum += *it;
         return sum;
     }
     void getBound(vector<int>& nums, double& min, double& max)
     {
         min = max = nums[0];
         for(auto it = nums.begin(); it < nums.end(); it++)
         {
            if(min > *it)
                min = *it;
            if(max < *it)
                max = *it;
         }
         return;
     }
     
    double maxAverage(vector<int> &nums, int k) {
        double lower;
        double upper;
        getBound(nums, lower, upper);
        
        double mid;
        while(upper - lower > 1e-6)
        {
            mid = lower + (upper - lower) / 2;
            if(judgeWhichSide(nums, mid, k))
                lower = mid;
            else
                upper = mid;
        }
        return lower;
    }
    
    bool judgeWhichSide(vector<int>& nums, double mid, int k)
    {
        double* sum_arr = new double[nums.size() + 1];
        sum_arr[0] = 0;
        double t_min = 0;
        for(int i = 1; i <= nums.size(); i++)
        {
            sum_arr[i] = sum_arr[i - 1] + nums[i - 1] - mid;
            if(i >= k)
            {
                if(sum_arr[i] >= t_min)
                    return true;
                t_min = min(t_min, sum_arr[i - k + 1]);
            }
            
        }
        delete[]sum_arr;
        return false;
    }
};
