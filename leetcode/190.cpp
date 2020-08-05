class Solution {
public:
    unordered_map<uint32_t, uint32_t> mp;
    uint32_t reverseBits(uint32_t n) {
        if(n == 0)
        {
            return 0;
        }
        auto found = mp.find(n);
        if(found != mp.end())
        {
            return found->second;
        }
        else
        {
            uint32_t original_n = n;
            uint32_t base = 0;
            for(int i = 0; i < sizeof(uint32_t) * 8; i++)
            {
                base <<= 1;
                if(n & 1)
                {
                    base += 1;
                }
                
                n >>= 1;
            }
            mp[original_n] = base;
            return base;
        }
    }
};
