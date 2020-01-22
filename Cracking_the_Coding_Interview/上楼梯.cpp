class GoUpstairs {
public:
    int countWays(int n) {
        vector<int> v{0, 1, 2, 4};
        for(int i = 4; i <= n; i++)
        {
            v.push_back(((v[i - 3] + v[i - 2]) % 1000000007 + v[i - 1]) % 1000000007);
        }
        return v[n];
    }
};
