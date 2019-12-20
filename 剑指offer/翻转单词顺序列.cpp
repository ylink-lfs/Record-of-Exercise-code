class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());
        stringstream st(str);
        string t;
        string res;
        if(str == " ")
            return " ";
        if(str == "  ")
            return "  ";
        if(str == "   ")
            return "   ";
        if(str == "    ")
            return "    ";
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
