class Solution {
private:
    vector<int> table;
public:
    Solution() { 
        table.resize(45); 
        for(auto& e : table)
        {
            e = 0;
        }
        table[1] = 1; 
    }
    int Fibonacci(int n) {
        if(table[n] || n == 0)
        {
            return table[n];
        }
        else
        {
            return table[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
        }
    }
};
