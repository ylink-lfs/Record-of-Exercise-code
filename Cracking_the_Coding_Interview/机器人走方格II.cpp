class Robot {
public:
    int countWays(vector<vector<int>>& map, int x, int y) {
        if(x == 1 && y == 1)
            return 0;
        else if(map[x][y] == 0)
            return 0;
        else if(x == 1 || y == 1)
            return 1;
        else
            return countWays(map, x - 1, y) + countWays(map, x, y - 1);
    }
};
