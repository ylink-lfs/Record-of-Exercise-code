class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        if(AB[0] == AB[1])
        {
            ;
        }
        else
        {
            AB[1] = AB[0] ^ AB[1];
            AB[0] = AB[0] ^ AB[1];
            AB[1] = AB[0] ^ AB[1];
        }
        return AB;
    }
};
