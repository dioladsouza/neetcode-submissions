class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited.insert(0);

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                if (neighbor == parent) {
                    continue;
                }
                if (visited.count(neighbor)) {
                    return false;
                }
                visited.insert(neighbor);
                q.push({neighbor, node});
            }
        }

        return visited.size() == n;
    }
};