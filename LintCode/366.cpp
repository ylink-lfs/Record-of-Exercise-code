class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        int arr[100] = {0, 1, 1};
        for(int i = 0; i < n; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n - 1];
    }
};
