class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param i: A bit position
     * @param j: A bit position
     * @return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        int mbit_len = j - i + 1;
        //Note that sizefof() return value in bytes
        int leftshit_m = (sizeof(int) << 3) - mbit_len;
        int rightshift_m = leftshit_m - i;
        unsigned m_mask = ~(static_cast<unsigned>((~m) << leftshit_m) >> rightshift_m);
        int leftshift_n = (sizeof(int) << 3) - j - 1;
        int rightshift_n = i;
        unsigned n_shift = static_cast<unsigned>((-1) << leftshift_n) >> (leftshift_n + rightshift_n) << rightshift_n;
        unsigned n_mask = n | n_shift;
        return m_mask & n_mask;
    }
};
