class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> arr) {
        int sum = arr[0];
        int maxsum = sum;
        for(int i = 1; i < arr.size(); i++)
        {
            sum = max(sum + arr[i], arr[i]);
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};
