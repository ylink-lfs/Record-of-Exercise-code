class Solution {
private:
    priority_queue<int, vector<int>, greater<int>> minhp;
    priority_queue<int, vector<int>, less<int>> maxhp;
public:
    void Insert(int num)
    {
        if(minhp.empty() && maxhp.empty())
        {
            maxhp.push(num);
        }
        else if(minhp.empty())
        {
            minhp.push(num);
            if(maxhp.top() > minhp.top())
            {
                int curmax = maxhp.top();
                int curmin = minhp.top();
                maxhp.pop();
                maxhp.push(curmin);
                minhp.pop();
                minhp.push(curmax);
            }
        }
        else if((minhp.size() + maxhp.size()) % 2 == 0)
        {
            maxhp.push(num);
            int curmax = maxhp.top();
            maxhp.pop();
            minhp.push(curmax);
        }
        else
        {
            minhp.push(num);
            int curmin = minhp.top();
            minhp.pop();
            maxhp.push(curmin);
        }
    }

    double GetMedian()
    { 
        if((minhp.size() + maxhp.size()) % 2 == 0)
        {
            int cur1 = minhp.top(), cur2 = maxhp.top();
            return double(cur1 + cur2) / 2;
        }
        else
        {
            return maxhp.size() > minhp.size() ? maxhp.top() : minhp.top();
        }
        
    }

};
