class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        else if(s1.empty() && s2.empty())
            return true;
        else
        {
            int times = s1.size();
            for(int i = 0; i < times; i++)
            {
                if(s1 == s2)
                    return true;
                rotate(s1.begin(), s1.begin() + 1, s1.end());
            }
            return false;
        }
    }
};
