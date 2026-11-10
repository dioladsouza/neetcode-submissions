class Solution {
private:
    int adj_row_idx[4] = {-1, 0, 1, 0};
    int adj_col_idx[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < 4; i++)
        {
            int neighbor_row = row + adj_row_idx[i];
            int neighbor_col = col + adj_col_idx[i];

            if(neighbor_row >= 0 && neighbor_row < m && 
            neighbor_col >= 0 && neighbor_col < n && 
            board[neighbor_row][neighbor_col] == 'O' && 
            !visited[neighbor_row][neighbor_col])
                dfs(neighbor_row, neighbor_col, board, visited);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        //traverse the boundaries of board
        //traverse row boundary
        for(int j = 0; j < n; j++)
        {
            //first row
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, board, visited);
            //last row
            if(board[m - 1][j] == 'O' && !visited[m - 1][j])
                dfs(m - 1, j, board, visited);
        }
        //traverse column boundary
        for(int i = 0; i < m; i++)
        {
            //first col
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, board, visited);
            //last col
            if(board[i][n - 1] == 'O' && !visited[i][n - 1])
                dfs(i, n - 1, board, visited);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
