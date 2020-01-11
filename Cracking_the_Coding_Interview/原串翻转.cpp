class Reverse {
public:
    string reverseString(string iniString) {
        stringstream st(iniString);
        int read_cnt = 0;
        string t;
        string res;
        while(st >> t)
        {
            read_cnt++;
            reverse(t.begin(), t.end());
            res += t;
            res += ' ';
        }
        if(read_cnt)
        {
            res.pop_back();
        }
        else
        {
            res = iniString;
        }
        return res;
    }
};
