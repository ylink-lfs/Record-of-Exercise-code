class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() <= 1)
            return str;
        n %= str.size();
        if(n == 0)
            return str;
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin() + str.size() - n);
        reverse(str.rbegin(), str.rbegin() + n);
        return str;
    }
};
