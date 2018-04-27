class Solution {
public:
    bool detectCapitalUse(string word) {
        string::iterator it;
        int upper_counter = 0;
        int lower_counter = 0;
        for(it = word.begin(); it != word.end(); it++)
        {
            if(isupper(*it))
                upper_counter++;
            if(islower(*it))
                lower_counter++;
        }
        if(upper_counter == word.size() || lower_counter == word.size())
            return true;
        else if (upper_counter == 1 && isupper(word[0]))
            return true;
        else
            return false;
    }
};
