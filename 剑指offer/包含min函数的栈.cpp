class Solution {
public:
    Solution() : st(), cur_min(0x7fffffff) {}
    void push(int value) {
        st.push(value);
        if(value < cur_min)
        {
            cur_min = value;
        }
    }
    void pop() {
        if(this->top() != cur_min)
        {
            st.pop();
        }
        else
        {
            st.pop();
            if(st.empty())
            {
                cur_min = 0x7fffffff;
            }
            else
            {
                cur_min = st.top();
                stack<int> t;
                while(!st.empty())
                {
                    t.push(st.top());
                    if(cur_min > st.top())
                    {
                        cur_min = st.top();
                    }
                    st.pop();
                }
                while(!t.empty())
                {
                    st.push(t.top());
                    t.pop();
                }
            }
            
        }
    }
    int top() {
        return st.top();
    }
    int min() {
        return cur_min;
    }
private:
    stack<int> st;
    int cur_min;
};
