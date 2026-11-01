class Solution {
int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void dfs(int row, int col, vector<vector<char>>& grid)
{
    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
        return;
    
    //mark as visited
    grid[row][col] = '0';
    for(int i = 0; i < 4; i++)
        dfs(row + directions[i][0], col + directions[i][1], grid);
}
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    islands += 1;
                }

            }
        }
        return islands;
    }
};