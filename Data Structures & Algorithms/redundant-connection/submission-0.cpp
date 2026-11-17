class Solution {
private:
    bool dfs(int current_node, int parent_node, vector<bool>& visited, vector<vector<int>>& adj_list)
    {
        if(visited[current_node])
            return true;
        visited[current_node] = true;
        for(auto neighbor : adj_list[current_node])
        {
            if(neighbor == parent_node)
                continue;
            if(dfs(neighbor, current_node, visited, adj_list))
                return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj_list(n + 1);

        //build the adjacency list
        for(auto edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);

            vector<bool> visited(n + 1, false);

            if(dfs(edge[0], -1, visited, adj_list))
                return {edge[0], edge[1]};
        }

        return {};
    }
};
