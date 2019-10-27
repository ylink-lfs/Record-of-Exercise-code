class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k > input.size())
            return vector<int>();
        priority_queue<int, vector<int>, greater<int>> pq;
        for_each(input.begin(), input.end(), [&](const int& e){
            pq.push(e);
        });
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
