//This problem has strict time limit. I have to write Binary Search inside the given function
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
        set<int> no_repeation;
        sort(nums1.begin(), nums1.end());
        
        auto it = nums2.begin();
        int lower = 0;
        int upper = nums1.size() - 1;
        int mid;

        while(it != nums2.end())
        {
            int tag = -1;
            
            lower = 0;
            upper = nums1.size() - 1;

            while(lower <= upper)
            {
                mid = lower + (upper - lower) / 2;
                if(nums1[mid] == *it)
                {
                    tag = mid;
                    break;
                }
                else if (nums1[mid] < *it)
                     lower = mid + 1;
                else
                     upper = mid - 1;
            }
            
            if(tag != -1 && no_repeation.find(*it) == no_repeation.end())
            {
                no_repeation.insert(*it);
                res.push_back(*it);
            }
            it++;
        }
        return res;
    }
};
