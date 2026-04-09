class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1)
            return true;

        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for(auto &pre : prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        int currCourses = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            currCourses++;

            for(int neigh : adj[front]){
                indegree[neigh]--;

                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return currCourses == numCourses;
    }
};
