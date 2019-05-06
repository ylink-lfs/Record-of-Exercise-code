class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i1 = 0, i2 = 1;
        while(i1 < A.size() && i2 < A.size())
        {
            while(i1 < A.size() && (i1 % 2 == 0 && A[i1] % 2 == 0))
                i1 += 2;
            if(i1 >= A.size())
                break;
            while(i2 < A.size() && (i2 % 2 != 0 && A[i2] % 2 != 0))
                i2 += 2;
            if(i2 >= A.size())
                break;
            swap(A[i1], A[i2]);
            i1 += 2;
            i2 += 2;
        }
        return A;
    }
};
