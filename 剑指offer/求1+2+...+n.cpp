template<int n>
struct solve{ enum val{N = solve<n - 1>::N + n}; };
template<>
struct solve<1>{ enum val{N=1}; };

class Solution {
public:
    int Sum_Solution(const int n) {
        return solve<n>::N;
    }
};
