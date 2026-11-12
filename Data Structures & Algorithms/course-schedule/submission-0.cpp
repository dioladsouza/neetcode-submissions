class Solution {
public:
    unordered_map<int, vector<int>> courseMap;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++)
            courseMap[i] = {};

        //map courses to their list of prerequisites
        for(auto it : prerequisites)
            courseMap[it[0]].push_back(it[1]);

        //iterate over every course
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i))
                return false;
        }
        return true;
    }
    bool dfs(int course)
    {
        if(visited.find(course) != visited.end())
            return false;
        if(courseMap[course].empty())
            return true;

        visited.insert(course);
        for(int c : courseMap[course])
            if(!dfs(c))
                return false;
        visited.erase(course);
        courseMap[course] = {};
        return true;
    }
};
