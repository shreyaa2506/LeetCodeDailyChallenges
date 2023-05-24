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
    void dfs(Node*node, Node*clone, vector<Node*>&visited){
        visited[node->val]=clone;
        for(auto it:node->neighbors){
            if(!visited[it->val]){
                Node*newNode = new Node(it->val);
                clone->neighbors.push_back(newNode);
                dfs(it,newNode,visited);
            }
            else{
                clone->neighbors.push_back(visited[it->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node*clone = new Node(node->val);
        vector<Node*>visited(1000,NULL);
        dfs(node,clone,visited);
        return clone;
    }
};