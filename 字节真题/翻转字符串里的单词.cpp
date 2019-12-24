class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        stringstream st(s);
        string t;
        string res;
        while(st >> t)
        {
            reverse(t.begin(), t.end());
            res += t;
            res += ' ';
        }
        res.pop_back();
        return res;
    }
};
