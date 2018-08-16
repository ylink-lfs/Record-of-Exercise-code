class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) 
    {
        int res = a ^ b;
        int shift_step = 0;
        while(shift_step <= sizeof(int) * 8)
        {
            if(((unsigned(a) >> shift_step) & 1) && ((unsigned(b) >> shift_step) & 1))
            {
                do
                {
                    res ^= (1 << (shift_step + 1));
                    shift_step++;
                } while(res && !(res & (1 << shift_step)));
                shift_step--;
            }
            shift_step++;
        }
        return res;
    }
};
