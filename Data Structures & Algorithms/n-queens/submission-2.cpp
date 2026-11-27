class Solution {
private:
    bool canPlaceQ(int row, int col, int n, vector<string>& board, vector<vector<string>>& result)
    {
        int row_copy = row;
        int col_copy = col;

        //check for north west diagonal
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = row_copy;
        col = col_copy;

        //check for same row 
        while(col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            col--;
        }

        row = row_copy;
        col = col_copy;

        //check for south west diagonal
        while(row < n && col >= 0)
        {
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }
    void backtrackFunc(int col, int n, vector<string>& board, vector<vector<string>>& result)
    {
        if(col == n)
        {
            result.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++)
        {
            if(canPlaceQ(row, col, n, board, result))
            {
                board[row][col] = 'Q';
                backtrackFunc(col + 1, n, board, result);
                board[row][col] = '.';            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrackFunc(0, n, board, result);
        return result;
    }
};
