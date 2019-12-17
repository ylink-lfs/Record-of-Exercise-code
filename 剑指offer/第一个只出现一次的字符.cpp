class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<pair<char, int>> char2cnt;
        unordered_map<char, int> char2pos;
        unordered_map<char, int> char2strpos;
        for(int i = 0; i < str.size(); i++)
        {
            if(char2pos.find(str[i]) == char2pos.end())
            {
                char2cnt.push_back(make_pair(str[i], 1));
                char2pos[str[i]] = char2cnt.size() - 1;
                char2strpos[str[i]] = i;
            }
            else
            {
                char2cnt[char2pos[str[i]]].second += 1;
            }
        }
        for(int i = 0; i < char2cnt.size(); i++)
        {
            if(char2cnt[i].second == 1)
            {
                return char2strpos[char2cnt[i].first];
            }
        }
        return -1;
    }
};
