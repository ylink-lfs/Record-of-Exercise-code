class Same {
public:
    bool checkSam(string stringA, string stringB) {
        map<char, int> sa, sb;
        for(int i = 0; i < stringA.size(); i++)
        {
            if(sa.find(stringA[i]) != sa.end())
            {
                sa[stringA[i]]++;
            }
            else
            {
                sa[stringA[i]] = 1;
            }
        }
        for(int i = 0; i < stringB.size(); i++)
        {
            if(sb.find(stringB[i]) != sb.end())
            {
                sb[stringB[i]]++;
            }
            else
            {
                sb[stringB[i]] = 1;
            }
        }
        return sa == sb;
    }
};
