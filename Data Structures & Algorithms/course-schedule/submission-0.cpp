class Solution {
public:
    bool dfs3(int course, unordered_map<int, vector<int>> &preMap, unordered_set<int> &visited){
        if(visited.count(course)) return false; // Visiting the same node in the same travesal
        if(preMap[course].empty()) return true; // The current course / node doesn't have any prerequisite

        visited.insert(course);

        for(int pre : preMap[course]){
            if(!dfs3(pre, preMap, visited))
                return false;
        }

        visited.erase(course);
        preMap[course] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        if(numCourses == 1)
            return true;

        unordered_set<int> visited;
        unordered_map<int, vector<int>> preMap;

        for(int i = 0; i < numCourses; i++)
            preMap = {};

        for(auto &x : prerequisites){
            preMap[x[0]].push_back(x[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!dfs3(i, preMap, visited))
                return false;
        }

        return true;
    }
};
