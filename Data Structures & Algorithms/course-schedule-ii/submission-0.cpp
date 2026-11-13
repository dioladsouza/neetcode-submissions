class Solution {
private:
    unordered_map<int, vector<int>> courseMap;
    unordered_set<int> visited;
    unordered_set<int> hasCycle;
    vector<int> output;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //intialize courseMap tp an empty list
        for(int i = 0; i < numCourses; i++)
            courseMap[i] = {};

        //map courses to their list of prerequisites
        for(auto it : prerequisites)
            courseMap[it[0]].push_back(it[1]);
        
        for(int i = 0; i < numCourses; i++)
            if(!dfs(i))
                return {};
        return output;
    }
    bool dfs(int course)
    {
        if(hasCycle.count(course))
            return false;
        if(visited.count(course))
            return true;
        
        hasCycle.insert(course);
        for(int c : courseMap[course])
        {
            if(!dfs(c))
                return false;
        }
        hasCycle.erase(course);
        output.push_back(course);
        visited.insert(course);
        return true;
    }
};