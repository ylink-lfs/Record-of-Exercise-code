class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        stack<int> st2, st3;
        for(auto it = numbers.begin(); it < numbers.end(); it++)
        {
            int curnum = *it;
            if(st2.empty() || curnum >= st2.top())
            {
                st2.push(curnum);
            }
            else
            {
                while(!st2.empty() && st2.top() > curnum)
                {
                    st3.push(st2.top());
                    st2.pop();
                }
                st2.push(curnum);
                while(!st3.empty())
                {
                    st2.push(st3.top());
                    st3.pop();
                }
            }
        }
        vector<int> res;
        while(!st2.empty())
        {
            res.push_back(st2.top());
            st2.pop();
        }
        return res;
    }
};
