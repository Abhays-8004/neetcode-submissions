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
//bfs se solution likhana h

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*>oldtonew;
        if(node == NULL){
            return NULL;
        }

        queue<Node*>q;
        q.push(node);
        oldtonew[node] = new Node(node->val);

        while(!q.empty()){
          Node* curr = q.front();
          q.pop();
          for(Node* n:curr->neighbors){
            if(oldtonew.find(n) == oldtonew.end()){
                oldtonew[n] = new Node(n->val);
                q.push(n);
            }
            oldtonew[curr]->neighbors.push_back(oldtonew[n]);
          }
        }
        return oldtonew[node];
    }
};
