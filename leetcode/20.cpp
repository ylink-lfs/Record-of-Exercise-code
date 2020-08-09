class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(auto e : str)
        {
            if(e == '(' || e == '[' || e == '{')
            {
                s.push(e);
            }
            else if(e == ')')
            {
                if(s.empty())
                {
                    return false;
                }
                else if(s.top() != '(')
                {
                    return false;
                }
                else
                {
                    s.pop();
                    continue;
                }
            }
            else if(e == ']')
            {
                if(s.empty())
                {
                    return false;
                }
                else if(s.top() != '[')
                {
                    return false;
                }
                else
                {
                    s.pop();
                    continue;
                }
            }
            else
            {
                if(s.empty())
                {
                    return false;
                }
                else if(s.top() != '{')
                {
                    return false;
                }
                else
                {
                    s.pop();
                    continue;
                }
            }
        }
        return s.empty();
    }
};
