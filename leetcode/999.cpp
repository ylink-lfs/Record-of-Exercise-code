class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        pair<int, int> root_pos;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'R')
                {
                    root_pos.first = i, root_pos.second = j;
                    break;
                }
            }
        }
        int total_cnt = 0;
        for(int i = root_pos.first - 1; i >= 0; i--)
        {
            if(board[i][root_pos.second] == 'B')
            {
                break;
            }
            else if (board[i][root_pos.second] == 'p')
            {
                total_cnt++;
                break;
            }
        }
        for(int i = root_pos.first + 1; i < board.size(); i++)
        {
            if(board[i][root_pos.second] == 'B')
            {
                break;
            }
            else if (board[i][root_pos.second] == 'p')
            {
                total_cnt++;
                break;
            }
        }
        for(int i = root_pos.second - 1; i >= 0; i--)
        {
            if(board[root_pos.first][i] == 'B')
            {
                break;
            }
            else if (board[root_pos.first][i] == 'p')
            {
                total_cnt++;
                break;
            }
        }
        for(int i = root_pos.second + 1; i < board.size(); i++)
        {
            if(board[root_pos.first][i] == 'B')
            {
                break;
            }
            else if (board[root_pos.first][i] == 'p')
            {
                total_cnt++;
                break;
            }
        }
        return total_cnt;
    }
};
