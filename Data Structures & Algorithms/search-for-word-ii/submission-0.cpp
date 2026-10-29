struct Node {
    Node* links[26];
    string flag = "";

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = nullptr;
    }

    static Node* addWord(vector<string>& words)
    {
        Node* root = new Node();
        for(string word : words)
        {
            Node* node = root;
            for(char ch : word)
            {
                if(node->links[ch - 'a'] == NULL)
                    node->links[ch - 'a'] = new Node();
                node = node->links[ch - 'a'];
            }
            node->flag = word;
        }
        return root;
    }
};

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, Node* node, vector<string>& result)
    {
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return;
        
        char ch = board[row][col];
        if(ch == '#' || node->links[ch - 'a'] == NULL)
            return;

        node = node->links[ch - 'a'];
        if (!node->flag.empty()) {
            result.push_back(node->flag);
            node->flag = "";
        }
 
        // Mark the cell so the current path does not reuse it.
        board[row][col] = '#';
 
        dfs(row + 1, col, board, node, result);
        dfs(row - 1, col, board, node, result);
        dfs(row, col + 1, board, node, result);
        dfs(row, col - 1, board, node, result);

        board[row][col] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = Node::addWord(words);

        vector<string> result;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                dfs(i, j, board, root, result);
            }
        }
        return result;
    }
};