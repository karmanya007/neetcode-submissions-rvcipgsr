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
    Node* dfs(Node *oldNode, unordered_map<Node*, Node*> &old_to_new){
        if(old_to_new.count(oldNode))
            return old_to_new[oldNode];

        Node *newNode = new Node(oldNode->val);
        old_to_new[oldNode] = newNode;

        for(Node *neighbor : oldNode->neighbors){
            newNode->neighbors.push_back(dfs(neighbor, old_to_new));
        }
        return newNode;
    }

    Node *cloneGraph(Node *node){
        if(!node)
            return nullptr;

        unordered_map<Node*, Node*> old_to_new;
        return dfs(node, old_to_new);
    }

};
