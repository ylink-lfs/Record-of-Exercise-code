class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        int count_space = 0;
        for(int i = 0; i < iniString.size(); i++)
        {
            if(iniString[i] == ' ')
                count_space++;
        }
        iniString += string(2 * count_space, ' ');
        int step_factor = 2 * count_space;
        for(int i = length - 1; i >= 0; i--)
        {
            if(iniString[i] == ' ')
            {
                iniString[i + step_factor] = '0';
                iniString[i + step_factor - 1] = '2';
                iniString[i + step_factor - 2] = '%';
                step_factor -= 2;
            }
            else
            {
                iniString[i + step_factor] = iniString[i];
            }
        }
        return iniString;
    }
};
