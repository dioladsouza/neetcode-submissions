/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> node_map;
        return dfs(node, node_map);
    }

    Node* dfs(Node* node, map<Node*, Node*>& node_map) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node_map.count(node)) {
            return node_map[node];
        }

        Node* copy = new Node(node->val);
        node_map[node] = copy;

        for (Node* n : node->neighbors) {
            copy->neighbors.push_back(dfs(n, node_map));
        }

        return copy;
    }
};