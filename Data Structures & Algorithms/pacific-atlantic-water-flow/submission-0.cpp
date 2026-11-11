class Solution {
private:
    int adj_row_idx[4] = {-1, 0, 1, 0};
    int adj_col_idx[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& heights)
    {
        visited[row][col] = 1;
        int m = heights.size();
        int n = heights[0].size();

        for(int i = 0; i < 4; i++)
        {
            int nrow = row + adj_row_idx[i];
            int ncol = col + adj_col_idx[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] &&
            heights[nrow][ncol] >= heights[row][col])
                dfs(nrow, ncol, visited, heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        //traverse top and bottom row of island
        for(int j = 0; j < n; j++)
        {
            //first row
            dfs(0, j, pacific, heights);
            //last row
            dfs(m - 1, j, atlantic, heights);
        }
        //traverse left and right column of island
        for(int i = 0; i < m; i++)
        {
            //first col
            dfs(i, 0, pacific, heights);
            //last row
            dfs(i, n -1, atlantic, heights);
        }

        vector<vector<int>> result;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                    result.push_back({i, j});
            }
        }
        return result;
    }
};