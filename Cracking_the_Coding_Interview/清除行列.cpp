class Clearer {
public:
    vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        vector<pair<int, int>> zero_pos;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                    zero_pos.push_back(make_pair(i, j));
            }
        }
        for(int c = 0; c < zero_pos.size(); c++)
        {
            int x = zero_pos[c].first, y = zero_pos[c].second;
            for(int i = 0; i < n; i++)
            {
                mat[x][i] = mat[i][y] = 0;
            }
        }
        return mat;
    }
};
