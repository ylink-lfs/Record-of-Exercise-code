class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int v[], int length, int* duplication) {
        for(int i = 0; i < length; i++)
        {
            if(!validate_number(v[i], length))
            {
                return false;
            }
            else if(v[i] == v[v[i]] && i != v[i])
            {
                *duplication = v[i];
                return true;
            }
            else
            {
                while(v[i] != i)
                {
                    if(v[i] == v[v[i]])
                    {
                        *duplication = v[i];
                        return true;
                    }
                    std::swap(v[i], v[v[i]]);
                }
            }
        }
        return false;
    }
    bool validate_number(const int num, int upper_bnd)
    {
        if(num < 0 || num >= upper_bnd)
        {
            return false;
        }
        return true;
    }
};
