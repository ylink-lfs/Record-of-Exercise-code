class Solution {
public:
    
void clean_multiple_dash(string& s)
    {
        if(s.size() <= 1)
            return;
        auto it1 = s.begin();
        while(it1 < s.end())
        {
            //multiple dashes occur, clean them
            if(it1 < s.end() - 1 && *it1 == '/' && *(it1 + 1) == '/')
            {
                //find where multiple dashes end
                auto it2 = it1 + 1;
                while(it2 < s.end() && *it2 == '/')
                    it2++;
                it1 = s.erase(it1 + 1, it2);
            }
            else
            {
                it1++;
            }
        }
        if(s.size() > 1 && s[s.size() - 1] == '/')
            s.pop_back();
    }
    string simplifyPath(string path) {
        if(path.size() <= 1)
            return path;
        clean_multiple_dash(path);
        vector<string> path_route;
        auto main_it = path.begin() + 1;
        auto sub_it = main_it;
        while(sub_it < path.end())
        {
            while(sub_it < path.end() && *sub_it != '/')
            {
                sub_it++;
            }
            string cur_action = string(main_it, sub_it);
            if(cur_action == "..")
            {
                while(!path_route.empty() && *path_route.rbegin() == ".")
                    path_route.pop_back();
                if(!path_route.empty())
                    path_route.pop_back();
            }
            else
            {
                path_route.push_back(cur_action);
            }
            main_it = ((sub_it == path.end()) ? path.end() : (sub_it + 1));
            sub_it = main_it;
        }
        string final_res("/");
        for(const auto& e : path_route)
        {
            if(e != ".")
            {
                final_res += e;
                final_res += "/";
            }
        }
        final_res.pop_back();
        if(final_res.empty())
            final_res = "/";
        return final_res;
    }
};
