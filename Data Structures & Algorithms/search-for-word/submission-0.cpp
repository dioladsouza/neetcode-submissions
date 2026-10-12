class Solution {
private:
    vector<vector<bool>> visited;
    bool traverseBoard(vector<vector<char>>& board, string word, int r, int c, int i)
    {
        if(i >= word.size())
            return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || word[i] != board[r][c] || visited[r][c])
            return false;
        
        visited[r][c] = true;
        bool res;
        res = traverseBoard(board, word, r + 1, c, i + 1) || 
        traverseBoard(board, word, r - 1, c, i + 1) ||
        traverseBoard(board, word, r, c + 1, i + 1) ||
        traverseBoard(board, word, r, c - 1, i + 1);

        visited[r][c] = false;

        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        visited = vector<vector<bool>> (m, vector<bool> (n, false));

        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(traverseBoard(board, word, r, c, 0))
                    return true;
            }
        }
        return false;
    }
};