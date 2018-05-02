class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        if(A.size() == 0)
            return 0;
        int lower = 0;
        int upper = A.size() - 1;
        int mid;
        while(lower < upper)
        {
            mid = lower + (upper - lower) / 2;
            if(A[mid] >= target)
                upper = mid;
            else
                lower = mid + 1;
        }
        if(A[lower] != target && lower == A.size() - 1)
            return lower + 1;
        else
            return lower;
    }
};
