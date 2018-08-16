class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int modify_bits = a ^ b;
        int count = 0;
        while(modify_bits)
        {
            count++;
            modify_bits = modify_bits & (modify_bits - 1);
        }
        return count;
    }
};
