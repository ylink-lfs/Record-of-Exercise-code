class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int lower_b = 0;
        int upper_b = matrix.size() - 1;
        int mid;
        while(lower_b < upper_b)
        {
            if(matrix[lower_b + 1][0] > target || lower_b >= matrix.size() - 1)
                break;
            mid = lower_b + (upper_b - lower_b + 1) / 2;  //figure out why +1 later, I stuck here
            if(matrix[mid][0] > target)
                upper_b = mid - 1;
            else
                lower_b = mid;
        }
        int lower = 0;
        int upper = matrix[0].size();
        while(lower <= upper)
        {
            mid = lower + (upper - lower) / 2;
            if(matrix[lower_b][mid] == target)
                return true;
            else if (matrix[lower_b][mid] < target)
                lower = mid + 1;
            else
                upper = mid - 1;
        }
        return false;
    }
};
