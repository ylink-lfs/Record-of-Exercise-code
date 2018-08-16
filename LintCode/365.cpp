class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        int modify_num = num;
        int count = 0;
        while(modify_num)
        {
            count++;
            modify_num = modify_num & (modify_num - 1);
        }
        return count;
    }
};
