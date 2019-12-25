vector<vector<bool>> reached;
vector<int> areas;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        if(grid.empty() || grid[0].empty())
            return 0;
        reached.clear(); areas.clear();
        reached.resize(grid.size());
        for(auto& e : reached)
        {
            e.resize(grid[0].size());    
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(reached[i][j] == false && grid[i][j] == 1)
                {
                    int record_area = 0;
                    search(i, j, record_area, grid);
                    areas.push_back(record_area);
                }
            }
        }
        if(areas.empty())
            return 0;
        return *max_element(areas.begin(), areas.end());
    }
    
    void search(const int i, const int j, int& cur_area, const vector<vector<int>>& grid)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size())
            return;
        else if(reached[i][j] == true)
            return;
        else if(grid[i][j] == 0)
            return;
        else
        {
            cur_area++;
            reached[i][j] = true;
            search(i - 1, j, cur_area, grid);
            search(i, j - 1, cur_area, grid);
            search(i + 1, j, cur_area, grid);
            search(i, j + 1, cur_area, grid);
        }
    }
};
