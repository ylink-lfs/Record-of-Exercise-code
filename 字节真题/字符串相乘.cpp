class Solution {
public:
    string addon(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0")
            return num1 == "0" ? num2 : num1;
        else
        {
            if(num1.size() < num2.size())
                swap(num1, num2);
            //Insert 0 before 2 numbers for carry handling
            num2.insert(num2.begin(), num1.size() - num2.size() + 1, '0');
            num1.insert(num1.begin(), 1, '0');
            string res(num1.size(), '0');
            int carry_num = 0;
            //num1 and num2 currently have the same size
            for(int i = num1.size() - 1; i >= 0; i--)
            {
                int cur_add_res = (num1[i] - '0') + (num2[i] - '0') + carry_num;
                res[i] = cur_add_res % 10 + '0';
                carry_num = cur_add_res / 10;
            }
            while(*res.begin() == '0')
                res.erase(res.begin());
            return res;
        }
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        else if(num1 == "1" || num2 == "1")
            return num1 == "1" ? num2 : num1;
        else
        {
            string final_sum("0");
            if(num1.size() < num2.size())
                swap(num1, num2);
            //Generate an mid number for addition of sum
            for(auto num2_it = num2.rbegin(); num2_it < num2.rend(); num2_it++)
            {
                string cur_mul(multiply_single_digit(num1, *num2_it));
                for(int i = 0; i < num2_it - num2.rbegin(); i++)
                {
                    cur_mul.push_back('0');
                }
                final_sum = addon(final_sum, cur_mul);
            }
            return final_sum;
        }
    }
    
    string multiply_single_digit(const string& num1, const char num2)
    {
        if(num2 == '0')
            return "0";
        else if(num2 == '1')
            return num1;
        else
        {
            string res(num1);
            int carry_num = 0;
            for(int i = num1.size() - 1; i >= 0; i--)
            {
                int cur_digit_mul_res = (num1[i] - '0') * (num2 - '0') + carry_num;
                if(i != 0)
                {
                    res[i] = cur_digit_mul_res % 10 + '0';
                }
                else if(i == 0)
                {
                    carry_num = cur_digit_mul_res / 10;
                    if(carry_num == 0)
                    {
                        res[i] = cur_digit_mul_res % 10 + '0';
                    }
                    else
                    {
                        res.insert(res.begin(), 1, '0');
                        res[1] = cur_digit_mul_res % 10 + '0';
                        res[0] = carry_num + '0';
                        i = 0;
                    }
                }
                carry_num = cur_digit_mul_res / 10;
            }
            while(*res.begin() == '0')
                res.erase(res.begin());
            return res;
        }
    }
};
