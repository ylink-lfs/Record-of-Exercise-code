class Transform {
public:
    int calcCost(int A, int B) {
        return count_one(A ^ B);
    }
    
    int count_one(int x)
    {
        int cnt = 0;
        while(x)
        {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }
};
