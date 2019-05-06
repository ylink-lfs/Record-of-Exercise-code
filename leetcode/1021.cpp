class Solution {
public:
    string removeOuterParentheses(string S) {
        string final_res = "";
        int balance = 0;
        int i, split_start;
        i = 0;
        split_start = 0;
        while(i < S.size())
        {
            do
            {
                switch (S[i])
                {
                    case '(': balance--; break;
                    case ')': balance++; break;
                }
                i++;
            } while(balance != 0);
            final_res += S.substr(split_start + 1, i - split_start - 2);
            split_start = i;
        }
        return final_res;
    }
};
