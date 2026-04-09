class Solution {
public:
    bool dfs4(int node, int parent, vector<vector<int>> &adj, unordered_set<int> &visited){
        if(visited.count(node)) // Loop detected
            return false;

        visited.insert(node);

        for(int &neighbour : adj[node]){
            if(neighbour == parent) // Don't visit the parent twice
                continue;

            if(!dfs4(neighbour, node, adj, visited))
                return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>> &edges){
        if(edges.size() > n - 1)
            return false; // For a acyclic graph, E = N - 1

        vector<vector<int>> adj(n);

        // Create adj list
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited;
        if(!dfs4(0, -1, adj, visited))
            return false;

        // Check if all the components are connected
        return visited.size() == n;
    }
};
