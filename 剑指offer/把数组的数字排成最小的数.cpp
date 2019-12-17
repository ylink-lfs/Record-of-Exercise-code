class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        if(numbers.empty())
        {
            return string("");
        }
        sort(numbers.begin(), numbers.end());
        vector<string> dp_s(numbers.size());
        dp_s[0] = to_string(numbers[0]);
        for(int i = 1; i < dp_s.size(); i++)
        {
            dp_s[i] = ((dp_s[i - 1] + to_string(numbers[i])) < (to_string(numbers[i]) + dp_s[i - 1]))
                 ? (dp_s[i - 1] + to_string(numbers[i])) : (to_string(numbers[i]) + dp_s[i - 1]);
        }
        return dp_s[dp_s.size() - 1];
    }
};
