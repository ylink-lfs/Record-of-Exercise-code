class Exchange {
public:
    int exchangeOddEven(int x) {
        int odd  = ((x&0x55555555)<<1);        
        int even = ((x&0xAAAAAAAA)>>1)&0x7fffffff;          
        return even|odd;
    }
};
