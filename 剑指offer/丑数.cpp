class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index == 1)
        {
            return 1;
        }
        else
        {
            vector<int> uglynums;
            uglynums.push_back(1);
            //first position whose num multiply the factor is bigger than all uglynums
            int posto2 = 0, posto3 = 0, posto5 = 0;
            auto getminof3 = [](const int n1, const int n2, const int n3)->int {
                return min(n1, min(n2, n3));
            };
            while(uglynums.size() < index)
            {
                int new1 = uglynums[posto2] * 2, new2 = uglynums[posto3] * 3, new3 = uglynums[posto5] * 5;
                int num2push = getminof3(new1, new2, new3);
                uglynums.push_back(num2push);
                while(uglynums[posto2] * 2 <= num2push)
                    posto2++;
                while(uglynums[posto3] * 3 <= num2push)
                    posto3++;
                while(uglynums[posto5] * 5 <= num2push)
                    posto5++;
            }
            
            return uglynums[index - 1];
        }
    }
};
