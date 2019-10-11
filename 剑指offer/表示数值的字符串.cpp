class Solution {
public:
    bool isNumeric(char* st)
    {
        if(st == nullptr)
        {
            return false;
        }
        
        string s(st);
        int epos = -1;
        auto isE = [](const char ch) {
            return ch == 'E' || ch == 'e';
        };
        auto is_sign = [](const char ch) {
            return ch == '-' || ch == '+';
        };
        auto is_numeric = [](const char ch) {
            return ch >= '0' && ch <= '9';
        };
        auto is_dot = [](const char ch) {
            return ch == '.';
        };
        
        for(int i = 0; i < s.size(); i++)
        {
            if(isE(s[i]) && epos == -1)
            {
                epos = i;
            }
            //Dup e character
            else if(isE(s[i]) && epos != -1)
            {
                return false;
            }
            //Invalid character
            else if(!isE(s[i]) && !is_sign(s[i]) && !is_numeric(s[i]) && !is_dot(s[i]))
            {
                return false;
            }
        }
        
        //Has 'e' but no additional number, invalid
        if(epos == s.size() - 1)
        {
            return false;
        }
        //No 'e' character
        else if(epos == -1)
        {
            return validate_integer(s) || validate_float(s);
        }
        //Scientific notation
        else
        {
            string preE(s.substr(0, epos));
            string afterE(s.substr(epos + 1, s.size() - epos - 1));
            return (validate_integer(preE) || validate_float(preE)) && validate_integer(afterE);
        }
    }
    
    bool validate_integer(const string& s)
    {
        return !dot_exists(s) && validate_sign_symbol(s);
    }
    
    bool validate_float(const string& s)
    {
        return dot_exists(s) && validate_dot(s) && validate_sign_symbol(s);
    }
    
    bool validate_sign_symbol(const string& s)
    {
        //Sign symbol should appear at the first position
        //or just doesn't exist at all
        //Duplicate symbols and symbol in the middle of the number
        //is not accepted
        for(int i = 1; i < s.size(); i++)
        {
            //Duplicate symbol and inappropriate symbol position
            if(s[i] == '+' || s[i] == '-')
            {
                return false;
            }
        }
        return true;
    }
    
    bool validate_dot(const string& s)
    {
        //dot should not duplicate
        int cnt_dot = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(cnt_dot > 1)
            {
                return false;
            }
            else if(s[i] == '.')
            {
                cnt_dot++;
            }
        }
        return true;
    }
    
    bool dot_exists(const string& s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '.')
            {
                return true;
            }
        }
        return false;
    }
    
    bool without_sign_prefix(const string& s)
    {
        return (s[0] != '+') && (s[0] != '-');
    }
};
