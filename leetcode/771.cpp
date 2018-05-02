class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jew_counter = 0;
        for(auto it = S.begin(); it < S.end(); it++)
        {
            if(find(J.begin(), J.end(), *it) != J.end())
            {
                jew_counter++;
            }
        }
        return jew_counter;
    }
};
