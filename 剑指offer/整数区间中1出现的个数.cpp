class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        return num_of_1(to_string(n));
    }
    
    int num_of_1(const string& s)
    {
        if(s[0] == '0')
        {
            return 0;
        }
        else if(s.size() <= 1)
        {
            return 1;
        }
        else
        {
            auto build_base = [](const string& s)->string {
                string base("1");
                while(base.size() < s.size())
                    base += '0';
                return base;
            };
            string base(build_base(s));
            int top_1_cnt = 0;
            if(s[0] == '1')
            {
                top_1_cnt  = stoi(s) - stoi(base) + 1;
            }
            else
            {
                top_1_cnt = stoi(base);
            }
            int other_pos_cnt = (s[0] - '0') * (s.size() - 1) * pow(10, s.size() - 2);
            string subproblem(s.substr(1, s.size() - 1));
            return top_1_cnt + other_pos_cnt + num_of_1(subproblem);
        }
    }
};
