class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        stringstream sin;
        sin << paragraph;
        string cache;
        char board[2] = { '0', '\0'};
        map<string, int> mymap;
        while(sin >> cache)
        {
            for(int i = 0; i < cache.size(); i++)
            {
                if(isalpha(cache[i]))
                {
                    board[0] = tolower(cache[i]);
                    cache.replace(i, 1, board);
                }
                if(!isalpha(cache[i]))
                {
                    cache.replace(i, 1, "");
                    i = -1;
                }
            }
            if(mymap.find(cache) == mymap.end())
            {
                mymap[cache] = 1;
            }
            else
            {
                mymap[cache]++;
            }
        }
        for(auto it = mymap.begin(); it != mymap.end(); )
        {
            if(find(banned.begin(), banned.end(), it->first) != banned.end())
            {
                mymap.erase(it++);
            }
            else
            {
                it++;
            }
        }
        auto it = mymap.begin();
        auto max_it = mymap.begin();
        for(; it != mymap.end(); it++)
        {
            if(max_it->second < it->second)
                max_it = it;
        }
        return max_it->first;
    }
};
