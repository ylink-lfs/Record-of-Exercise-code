class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto& elem : A)
            reverse(elem.begin(), elem.end());
        for(auto& one_dim : A)
        {
            for(auto& elem : one_dim)
            {
                elem ^= 1;
            }
        }
        return A;
    }
};
