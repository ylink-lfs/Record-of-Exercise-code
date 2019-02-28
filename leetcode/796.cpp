class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.empty() && B.empty())
            return true;
        for(int i = 1; i < A.size(); i++)
        {
            rotateProcess(A);
            if(A == B)
            {
                return true;
            }
        }
        return false;
    }
    //p in the range (0, n)
    void rotateProcess(string& s)
    {
        auto adjust_num = [&](const int n) {
            return n < 0 ? n + s.size() : n;
        };
        for(int i = 1; i > 0; i--)
        {
            int guard_pos = i;
            int current_pos = i;
            int target_pos = adjust_num(current_pos - 1);
            char put_elem = s[current_pos];
            char tmp_elem;
            while(target_pos != guard_pos)
            {
                tmp_elem = s[target_pos];
                s[target_pos] = put_elem;
                put_elem = tmp_elem;
                target_pos = adjust_num(target_pos - 1);
                current_pos = adjust_num(current_pos - 1);
            }
            s[target_pos] = put_elem;
        }
    }
};
