class Solution {
int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int dfs(int rows, int cols, vector<vector<int>>& grid)
{
    if(rows < 0 || cols < 0 || rows >= grid.size() || cols >= grid[0].size() || grid[rows][cols] == 0)
        return 0;
    
    grid[rows][cols] = 0;
    int area = 1;
    for(int i = 0; i < 4; i++)
        area += dfs(rows + directions[i][0], cols + directions[i][1], grid);
    return area;
}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(i, j, grid));
            }
        }
        return maxArea;
    }
};
