class Finder {
public:
    int findString(vector<string> str, int n, string x) {
        vector<string> cleaned_str;
        map<int, int> mp;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] != "")
            {
                cleaned_str.push_back(str[i]);
                mp.insert(make_pair(cleaned_str.size() - 1, i));
            }
        }
        int lower = 0, upper = cleaned_str.size() - 1;
        while(lower <= upper)
        {
            int mid = lower + (upper - lower) / 2;
            if(cleaned_str[mid] < x)
            {
                lower = mid + 1;
            }
            else if(cleaned_str[mid] > x)
            {
                upper = mid - 1;
            }
            else
            {
                return mp[mid];
            }
        }
        return mp[lower];
    }
};
