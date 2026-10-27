struct Node {
    Node* wordList[26];
    bool flag = false;
};

class WordDictionary {
private:
    Node* root;

    bool dfs(string word, int j, Node* root)
    {
        Node* current = root;
        for(int i = j; i < word.size(); i++)
        {
            char ch = word[i];
            if(ch == '.')
            {
                for(Node* child : current->wordList)
                {
                    if(child != NULL && dfs(word, i + 1, child))
                        return true;
                }
                return false;
            }
            else
            {
                if(current->wordList[ch - 'a'] == NULL)
                    return false;
                current = current->wordList[ch - 'a'];
            }
        }
        return current->flag;
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* current = root;
        for(char ch : word)
        {
            if(current->wordList[ch - 'a'] == NULL)
                current->wordList[ch - 'a'] = new Node();
            current = current->wordList[ch - 'a'];
        }
        current->flag = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};