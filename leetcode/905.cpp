class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i1 = 0, i2 = A.size() - 1;
        while(i1 < i2)
        {
            while(i1 < i2 && A[i1] % 2 == 0)
                i1++;
            while(i1 < i2 && A[i2] % 2 != 0)
                i2--;
            std::swap(A[i1], A[i2]);
            i1++;
            i2--;
        }
        return A;
    }
};
