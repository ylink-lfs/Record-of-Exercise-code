class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++)
        {
            bool able = true;
            int board = i;
            do
            {
                int rest = board % 10;
                board /= 10;
                if(rest == 0)
                {
                    able = false;
                    break;
                }
                if(i % rest != 0)
                {
                    able = false;
                    break;
                }
            } while(board != 0);
            if(able == true)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
