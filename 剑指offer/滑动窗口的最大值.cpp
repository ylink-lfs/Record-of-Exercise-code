class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.empty() || size == 0 || num.size() < size)
            return res;
        else if(num.size() == size)
        {
            res.push_back(*max_element(num.begin(), num.end()));
        }
        else
        {
            auto cur_max_pos = max_element(num.begin(), num.begin() + size);
            res.push_back(*cur_max_pos);
            auto window_bg = num.begin();
            auto window_ed = num.begin() + size;
            do {
                window_bg++;
                window_ed++;
                if(cur_max_pos < window_bg)
                {
                    cur_max_pos = max_element(window_bg, window_ed);
                }
                else if(*cur_max_pos < *(window_ed - 1))
                {
                    cur_max_pos = window_ed - 1;
                }
                else
                {
                    //still the biggest in the new window
                    //push that element again
                }
                res.push_back(*cur_max_pos);
            } while(window_ed < num.end());
        }
        return res;
    }
};
