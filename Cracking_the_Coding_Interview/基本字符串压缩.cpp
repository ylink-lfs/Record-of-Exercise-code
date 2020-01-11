class Zipper {
public:
    string zipString(string iniString) {
        string zipped_str;
        for(int i = 0; i < iniString.size(); )
        {
            int same_char_pos = i;
            while(same_char_pos < iniString.size() && 
                  iniString[same_char_pos] == iniString[same_char_pos + 1])
                same_char_pos++;
            int repeat_num = same_char_pos - i + 1;
            zipped_str += iniString[i];
            zipped_str += to_string(repeat_num);
            i = same_char_pos + 1;
        }
        return zipped_str.size() < iniString.size() ? zipped_str : iniString;
    }
};
