class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto& elem : A)
            elem *= elem;
        sort(A.begin(), A.end());
        return A;
    }
};
