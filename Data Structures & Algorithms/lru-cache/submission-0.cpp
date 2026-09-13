class Node{
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void deleteNode(Node* node)
    {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertFront(Node* node)
    {
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end())
            return -1;
        
        Node* node = mpp[key];
        deleteNode(node);
        insertFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end())
        {
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertFront(node);
            return;
        }
        else
        {
            if(mpp.size() == capacity)
            {
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete(node);
            }
        }
        Node* newNode = new Node(key, value);
        insertFront(newNode);
        mpp[key] = newNode;
    }
};
