class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1)
            return words[0];

        unordered_set<int> alpha;
        for(string &w : words){
            for(char &c : w){
                if(!alpha.count(c - 'a')){
                    alpha.insert(c - 'a');
                }
            }
        }

        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);

        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];

            int n1 = w1.length();
            int n2 = w2.length();

            int idx = 0;
            while(idx < n1 && idx < n2 && w1[idx] == w2[idx])
                idx++;

            if(idx < n1 && idx >= n2) return "";
            if(idx >= n1 || idx >= n2) continue;

            adj[w1[idx] - 'a'].push_back(w2[idx] - 'a');
            indegree[w2[idx] - 'a']++;
        }

        queue<int> q;

        for(int x : alpha){
            if(!indegree[x])
                q.push(x);
        }

        string res = "";
        while(!q.empty()){
            int node = q.front();
            res += (q.front() + 'a');
            q.pop();

            for(int &neigh : adj[node]){
                indegree[neigh]--;

                if(!indegree[neigh])
                    q.push(neigh);
            }
        }

        if(res.length() != alpha.size())
            return "";

        return res;
    }
};
