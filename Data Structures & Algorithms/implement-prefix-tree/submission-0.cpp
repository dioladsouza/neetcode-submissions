struct Node {
    Node* links[26];
    bool flag = false;

    int containsChar(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
};
class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsChar(word[i]))
            {
                node->links[word[i] - 'a'] = new Node();
            }
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!node->containsChar(word[i]))
                return false;
            node = node->links[word[i] - 'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(!node->containsChar(prefix[i]))
                return false;
            node = node->links[prefix[i] - 'a'];
        }
        return true;
    }
};
