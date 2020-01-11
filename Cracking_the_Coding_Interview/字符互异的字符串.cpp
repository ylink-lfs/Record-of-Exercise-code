class Different {
public:
    bool checkDifferent(string iniString) {
        for(int i = 0; i < iniString.size() - 1; i++)
        {
            for(int j = i + 1; j < iniString.size(); j++)
            {
                if(iniString[i] == iniString[j])
                    return false;
            }
        }
        return true;
    }
};
