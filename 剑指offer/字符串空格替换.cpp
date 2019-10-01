class Solution {
public:
	void replaceSpace(char* str,int length) {
        if(str == NULL)
            return;
        int space_cnt = 0;
        for(int i = 0; i < length; i++)
        {
            if(str[i] == ' ')
            {
                space_cnt++;
            }
        }
        int i1 = length, i2 = length + space_cnt * 2;
        str[i2] = '\0';
        i1--;
        i2--;
        while(i1 >= 0)
        {
            if(isspace(str[i1]))
            {
                i1--;
                i2 -= 2;
                str[i2] = '%';
                str[i2 + 1] = '2';
                str[i2 + 2] = '0';
                i2--;
            }
            else
            {
                str[i2--] = str[i1--];
            }
        }
	}
};
