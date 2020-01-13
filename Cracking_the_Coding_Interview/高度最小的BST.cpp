class MinimalBST {
public:
    int buildMinimalBST(vector<int> vals) {
        if(vals.size() <= 1)
            return 1;
        int cap_power = 1;
        while(true)
        {
            int cmp_num = pow(2, cap_power) - 1 + 1e-8;
            if(cmp_num >= vals.size())
                break;
            else
                cap_power++;
        }
        return cap_power;
    }
    
};
