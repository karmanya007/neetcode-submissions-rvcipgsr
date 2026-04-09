class Solution {
public:
    void dfs5(int node, vector<vector<int>> &adj, unordered_set<int> &visited){
        visited.insert(node);

        for(int &neighbour : adj[node]){
            if(!visited.count(neighbour))
                dfs5(neighbour, adj, visited);
        }
    }

    int countComponents(int n, vector<vector<int>> &edges){
        vector<vector<int>> adj(n);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited;

        int components = 0;
        for(int i = 0; i < n; i++){
            if(!visited.count(i)){
                dfs5(i, adj, visited);
                components++;
            }
        }

        return components;
    }
};
