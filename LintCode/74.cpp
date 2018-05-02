class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int lower = 1;
        int upper = n;
        int mid;
        while(lower < upper)
        {
            mid = lower + (upper - lower + 1) / 2;
            if(SVNRepo::isBadVersion(mid))
            {
                upper = mid - 1;
            }
            else
            {
                lower = mid;
            }
        }
        return SVNRepo::isBadVersion(lower) ? lower : lower + 1;
    }
};
