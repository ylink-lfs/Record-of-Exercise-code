class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int low = 0, up = array.size() - 1;
        vector<int> res;
        if(array.empty())
            return res;
        else if(array.size() <= 2)
        {
            res.push_back(array[0]);
            res.push_back(array[0]);
            return res;
        }
        while(array[low] + array[up] != sum && low <= up)
        {
            if(array[low] + array[up] < sum)
                low++;
            else
                up--;
        }
        if(array[low] + array[up] != sum)
            return res;
        res.push_back(array[low]);
        res.push_back(array[up]);
        return res;
    }
};
