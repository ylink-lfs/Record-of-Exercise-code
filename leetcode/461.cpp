
class Solution {

public:

    int hammingDistance(int x, int y) {

        int board = x ^ y;

        int counter = 0;

        while(board != 0)

        {

            board &= (board - 1);

            counter++;

        }

        return counter;

    }

};
