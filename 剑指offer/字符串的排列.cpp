class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty())
            return vector<string>();
        vector<bool> colored(str.size());
        vector<char> characters;
        for_each(str.begin(), str.end(), [&](const char& e){
                characters.push_back(e);
            }
        );
        string cur_str;
        vector<string> res;
        int expected_size = str.size();
        recur_permutation(res, cur_str, colored, characters, expected_size);
        sort(res.begin(), res.end());
        auto it = unique(res.begin(), res.end());
        res.erase(it, res.end());
        return res;
    }
    
    void recur_permutation(vector<string>& res_store, string& cur_str,
                          vector<bool>& colored, vector<char>& character_set,
                           const int expected_size)
    {
        if(cur_str.size() == expected_size)
        {
            res_store.push_back(cur_str);
        }
        else
        {
            for(int i = 0; i < character_set.size(); i++)
            {
                if(!colored[i])
                {
                    colored[i] = true;
                    cur_str.push_back(character_set[i]);
                    recur_permutation(res_store, cur_str, colored, character_set, expected_size);
                    cur_str.pop_back();
                    colored[i] = false;
                }
            }
        }
    }
    
    
};
