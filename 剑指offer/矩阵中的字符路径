class Solution {
public:
    vector<vector<char>> mx;
    deque<deque<bool>> color;
    bool has_path_flag;
    void recur_find(const vector<vector<char>>& matrix,
                   deque<deque<bool>>& color,
                   const int cur_row, const int cur_col,
                   const string& pattern,
                   string& cur_str,
                   const int depth)
    {
        if(cur_row < 0 || cur_row >= matrix.size()
          || cur_col < 0 || cur_col >= matrix[0].size())
        {
            return;
        }
        else if(color[cur_row][cur_col])
        {
            return;
        }
        else if(has_path_flag)
        {
            return;
        }
        else
        {
            color[cur_row][cur_col] = true;
            cur_str.push_back(matrix[cur_row][cur_col]);
            if(cur_str == pattern)
            {
                has_path_flag = true;
            }
            else if(cur_str[depth] != pattern[depth])
            {
                ;
            }
            else
            {
                recur_find(mx, color, cur_row - 1, cur_col, pattern, cur_str, depth + 1);
                recur_find(mx, color, cur_row + 1, cur_col, pattern, cur_str, depth + 1);
                recur_find(mx, color, cur_row, cur_col - 1, pattern, cur_str, depth + 1);
                recur_find(mx, color, cur_row, cur_col + 1, pattern, cur_str, depth + 1);
            }
            cur_str.pop_back();
            color[cur_row][cur_col] = false;
            return;
        }
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(!matrix || !str || rows <= 0 || cols <= 0)
            return false;
        mx.clear();
        color.clear();
        mx.resize(rows);
        color.resize(rows);
        for(int i = 0; i < rows; i++)
        {
            mx[i].resize(cols);
            color[i].resize(cols);
            for(int j = 0; j < cols; j++)
            {
                mx[i][j] = matrix[i * cols + j];
                color[i][j] = false;
            }
        }
        has_path_flag = false;
        string needle = string(str);
        string s = string();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                s.clear();
                recur_find(mx, color, i, j, needle, s, 0);
                if(has_path_flag)
                {
                    has_path_flag = false;
                    return true;
                }
            }
        }
        return false;
    }
};
