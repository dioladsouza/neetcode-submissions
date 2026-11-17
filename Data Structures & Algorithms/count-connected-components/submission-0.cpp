class Solution {
private:
    void dfs(int i, vector<vector<int>>& adj_list, vector<int>& visited)
    {
        visited[i] = 1;
        for(auto neighbor : adj_list[i])
        {
            if(!visited[neighbor])
                dfs(neighbor, adj_list, visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //tracks nodes already visited
        vector<int> visited(n, 0);
        vector<vector<int>> adj_list(n);

        //build the adjacency list
        for(auto edge : edges)
        {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        int total = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, adj_list, visited);
                total++;
            }
        }
        return total;
    }
};
