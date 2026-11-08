class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //queue storing {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        int visited[m][n];
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                    visited[i][j] = 0;
            }
        }
        int max_time = 0;
        int adj_row_idx[4] = {-1, 0, 1, 0};
        int adj_col_idx[4] = {0, 1, 0, -1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            max_time = max(max_time, t);
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int neighbor_row = row + adj_row_idx[i];
                int neighbor_col = col + adj_col_idx[i];

                if(neighbor_row >= 0 && neighbor_row < m && neighbor_col >= 0 && neighbor_col < n 
                && grid[neighbor_row][neighbor_col] == 1 && visited[neighbor_row][neighbor_col] != 2)
                {
                    visited[neighbor_row][neighbor_col] = 2;
                    q.push({{neighbor_row, neighbor_col}, t + 1});
                }
            }
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] != 2)
                    return -1;
            }
        }
        return max_time;
    }
};
