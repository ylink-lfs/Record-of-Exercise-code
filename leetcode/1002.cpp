class Solution {
public:
    vector<string> commonChars(vector<string>& A) 
    {
        if (A.empty())
        {
            return vector<string>();
        }
        string first_word = A[0];
        map<string, int> mp;
        for (const auto& each_char : first_word)
        {
            string search_string(1, each_char);

            if (mp.find(search_string) == mp.end())
            {
                //Not found, insert it and give initial value
                mp[search_string] = 1;
            }
            else
            {
                //Found, increase the count
                mp[search_string]++;
            }
        }
        for (int i = 1; i < A.size(); i++)
        {
            string current_word = A[i];
            map<string, int> cur_mp;
            //if the char doesn't exist in current word, 
            for (const auto& each_char : current_word)
            {
                string search_string(1, each_char);
                if (cur_mp.find(search_string) == cur_mp.end())
                {
                    //Not found, insert it and give initial value
                    cur_mp[search_string] = 1;
                }
                else
                {
                    //Found, increase the count
                    cur_mp[search_string]++;
                }
            }
            //iterate the base mp
            //it the word doesn't exist in the current mp, then erase it
            for (auto it = mp.begin(); it != mp.end(); )
            {
                if (cur_mp.find(it->first) == cur_mp.end())
                {
                    mp.erase(it++);
                }
                else
                {
                    it++;
                }
            }
            //iterate the second mp
            //now the 2 mp shares the same chars
            //we need to get the minimum vale to the base mp
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                mp[it->first] = std::min(cur_mp.find(it->first)->second, mp[it->first]);
            }
        }
        //construct vector according to base_mp
        vector<string> res;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
           for(int i = 0; i < it->second; i++)
		        res.push_back(it->first);
        }
        return res;
    }
};
