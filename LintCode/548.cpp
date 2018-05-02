 //solved after watching hints. BTW, does this problem relate to Binary Division? Actually it uses "2 pointers" skill
class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0)
            return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if(nums1[nums1.size() - 1] < nums2[0] || nums1[0] > nums2[nums2.size() - 1])
            return res;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while(it1 != nums1.end() && it2 != nums2.end())
        {
            if(*it1 < *it2)
                it1++;
            else if (*it1 > *it2)
                it2++;
            else
            {
                res.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return res;
    }
};
