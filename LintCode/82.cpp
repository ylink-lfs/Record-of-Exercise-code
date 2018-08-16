class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int res = A[0];
        for(auto it = A.begin() + 1; it < A.end(); it++)
            res ^= *it;
        return res;
    }
};
