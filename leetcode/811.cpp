class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> mymap;
        auto vec_it = cpdomains.begin();
        while(vec_it != cpdomains.end())
        {
            int main_index = 0;
            string num_str;
            while((*vec_it)[main_index] != ' ')
            {
                num_str += (*vec_it)[main_index];
                main_index++;
            }
            int temp_count = stoi(num_str);
            
            auto sub_index = (*vec_it).size() - 1;
            while((*vec_it)[sub_index] != ' ')
            {
                if((*vec_it)[sub_index - 1] == '.' || sub_index - 1 == main_index)
                {
                    string temp_sub_str = (*vec_it).substr(sub_index, (*vec_it).size() - sub_index);
                    if(mymap.find(temp_sub_str) == mymap.end())
                    {
                        mymap[temp_sub_str] = temp_count;
                    }
                    else
                    {
                        mymap[temp_sub_str] += temp_count;
                    }
                }
                sub_index--;
            }
            vec_it++;
        }
        vector<string> res;
        auto it_m = mymap.begin();
        
        while(it_m != mymap.end())
        {
            string cache = to_string(it_m->second) + ' ' + it_m->first;
            res.push_back(cache);
            it_m++;
        }
        return res;
    }
};
