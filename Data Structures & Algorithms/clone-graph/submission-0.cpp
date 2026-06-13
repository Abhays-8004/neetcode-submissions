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
    Node* Dfs(Node* node,map<Node*,Node*>&oldtonew){
        if(node == NULL){
            return NULL;
        }

        if(oldtonew.count(node)){
            return oldtonew[node];
        }
        Node* clonenode = new Node(node->val);
        oldtonew[node] = clonenode;
        for(Node* n:node->neighbors){
            clonenode->neighbors.push_back(Dfs(n,oldtonew));
        }

        return clonenode;
    }
    Node* cloneGraph(Node* node) {
      map<Node* ,Node*>oldtonew;
      return Dfs(node,oldtonew);
    }
};
