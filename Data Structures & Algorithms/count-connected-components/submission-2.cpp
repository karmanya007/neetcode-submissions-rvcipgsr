class DSU{
private:
    vector<int> Parent, Size;

public:
    int components;

    DSU(int n){
        components = n;
        Parent.resize(n + 1);
        Size.resize(n + 1, 1);

        for(int i = 0; i < n; i++){
            Parent[i] = i;
        }
    }

    int findParent(int node){
        if(Parent[node] == node)
            return node;

        return Parent[node] = findParent(Parent[node]); // Path compression
    }
    bool unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv)
            return false; // Two connected nodes have the same parent, i.e a cycle is there

        components--;
        if(Size[pu] > Size[pv]){
            Parent[pv] = pu;
            Size[pu] += Size[pv];
        }
        else{
            Parent[pu] = pv;
            Size[pv] += Size[pu];
        }

        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
    DSU dsu(n);
    int components = n;

    for(auto &e : edges){
        if(dsu.unionBySize(e[0], e[1]))
            components--;
    }

    return components;
    }
};
