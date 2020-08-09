class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1, m2;
        for(auto e : s)
        {
            if(m1.find(e) == m1.end())
            {
                m1[e] = 1;
            }
            else
            {
                m1[e]++;
            }
        }
        for(auto e : t)
        {
            if(m2.find(e) == m2.end())
            {
                m2[e] = 1;
            }
            else
            {
                m2[e]++;
            }
        }
        return m1 == m2;
    }
};
