class Solution {
private:
    void backtrackFunc(int col, int n, vector<string>& board, vector<vector<string>>& result, vector<int>& checkRow, vector<int>& upperLeftDiagonal, vector<int>& lowerLeftDiagonal)
    {
        if(col == n)
        {
            result.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++)
        {
            if(checkRow[row] == 0 && upperLeftDiagonal[row + col] == 0 &&
            lowerLeftDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                checkRow[row] = 1;
                upperLeftDiagonal[row + col] = 1;
                lowerLeftDiagonal[n - 1 + col - row] = 1;
                backtrackFunc(col + 1, n, board, result, checkRow, upperLeftDiagonal, lowerLeftDiagonal);
                board[row][col] = '.';
                checkRow[row] = 0;
                upperLeftDiagonal[row + col] = 0;
                lowerLeftDiagonal[n - 1 + col - row] = 0;            
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<int> checkRow(n, 0), upperLeftDiagonal(2 * n - 1, 0), lowerLeftDiagonal(2 * n - 1, 0);
        backtrackFunc(0, n, board, result, checkRow, upperLeftDiagonal, lowerLeftDiagonal);
        return result;
    }
};
