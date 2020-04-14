// https://leetcode.com/problems/clone-graph/
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
    unordered_map<Node*,Node*> visit;

    void dfs(Node* origin, Node* current) {
        vector<Node*> nodes = origin->neighbors;
        for(auto n: nodes) {
            auto entry = visit.find(n);
            Node* tmp;
            if(entry==visit.end()) {
                tmp = new Node(n->val);
                visit[n] = tmp;
                dfs(n, tmp);
            } else {
                tmp = entry->second;
            }
            current->neighbors.push_back(tmp);
        }
    }
    
    void bfs(Node* node, Node* cloned) {
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* current = visit[q.front()];
            vector<Node*> nodes = q.front()->neighbors;
            q.pop();
            for(auto n: nodes) {
                auto entry = visit.find(n);
                Node* clonedChild;
                if(entry==visit.end()) {
                    clonedChild = new Node(n->val);            
                    visit[n] = clonedChild;
                    q.push(n);
                } else {
                    clonedChild = entry->second;
                }
                current->neighbors.push_back(clonedChild);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;

        Node* cloned = new Node(node->val);
        visit[node] = cloned;
        //dfs(node, cloned);        
        bfs(node, cloned);
        return cloned;
    }
};
