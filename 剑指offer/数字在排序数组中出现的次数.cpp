class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int leftbd = find_left_boundary(data, k), rightbd = find_right_boundary(data, k);
        if(data[leftbd] != k)
            return 0;
        return rightbd - leftbd + 1;
    }
    int find_left_boundary(const vector<int>& v, int k)
    {
        int left = 0, right = v.size() - 1, mid;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(v[mid] > k)
            {
                right = mid - 1;
            }
            else if(v[mid] < k)
            {
                left = mid + 1;
            }
            else
            {
                if(mid == 0 || v[mid - 1] != k)
                {
                    return mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return left;
    }
    int find_right_boundary(const vector<int>& v, int k)
    {
        int left = 0, right = v.size() - 1, mid;
        while(left < right)
        {
            mid = left + (right - left) / 2;
            if(v[mid] < k)
            {
                left = mid + 1;
            }
            else if(v[mid] > k)
            {
                right = mid - 1;
            }
            else
            {
                if(mid == v.size() - 1 || v[mid + 1] != k)
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return left;
    }
};
