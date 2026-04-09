/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *cloneGraph(Node *node){
        if(!node)
            return nullptr;

        Node *clonedNode = new Node(node->val);

        unordered_map<Node*, Node*> old_to_new;
        queue<Node*> q;
        q.push(node);
        old_to_new[node] = clonedNode;

        while(!q.empty()){
            Node *oldNode = q.front();
            q.pop();

            for(Node *neighbor : oldNode->neighbors){
                if(!old_to_new.count(neighbor)){
                    old_to_new[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                old_to_new[oldNode]->neighbors.push_back(old_to_new[neighbor]);
            }
        }

        return clonedNode;
    }
};
