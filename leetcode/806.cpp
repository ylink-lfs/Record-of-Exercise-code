class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int total = 0;
        for(string::iterator it = S.begin(); it < S.end(); it++)
        {
            if((total % 100) + widths[*it - 'a'] > 100)
            {
                total += (100 - total % 100) + widths[*it - 'a'];
            }
            else
            {
                total += widths[*it - 'a'];
            }
            
        }
        vector<int> res;
        int line = total / 100;
        int rest = total % 100;
        if(rest != 0)
            line++;
        else
            rest = 100;
        res.push_back(line);
        res.push_back(rest);
        return res;
    }
};
