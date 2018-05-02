class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> add_or_not;
        for(auto it = words.begin(); it != words.end(); it++)
        {
            string cache = transform(*it);
            add_or_not.insert(cache);
        }
        return add_or_not.size();
    }
    string transform(string& str)
    {
        auto it = str.begin();
        string res;
        while(it != str.end())
        {
            switch (*it)
            {
                case 'a':res += ".-"; break;
                case 'b':res += "-...";  break;
                case 'c':res += "-.-.";  break;
                case 'd':res += "-..";  break;
                case 'e':res += ".";  break;
                case 'f':res += "..-.";  break;
                case 'g':res += "--."; break;
                case 'h':res += "....";  break;
                case 'i':res += "..";  break;
                case 'j':res += ".---";  break;
                case 'k':res += "-.-";  break;
                case 'l':res += ".-..";  break;
                case 'm':res += "--";  break;
                case 'n':res += "-.";  break;
                case 'o':res += "---";  break;
                case 'p':res += ".--.";  break;
                case 'q':res += "--.-";  break;
                case 'r':res += ".-.";  break;
                case 's':res += "...";  break;
                case 't':res += "-";  break;
                case 'u':res += "..-";  break;
                case 'v':res += "...-";  break;
                case 'w':res += ".--";  break;
                case 'x':res += "-..-";  break;
                case 'y':res += "-.--";  break;
                case 'z':res += "--..";  break;
            }
            it++;
        }
        return res;
    }
};
