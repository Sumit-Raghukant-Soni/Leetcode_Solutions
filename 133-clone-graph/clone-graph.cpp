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
    Node* createClone(Node* node, unordered_map<Node*, Node*>& mp){
        if(!node) return NULL;

        Node* root = new Node(node->val);
        mp[node] = root;
        
        for(Node* n : node->neighbors){
            if(mp.find(n) == mp.end()){
                root->neighbors.push_back(createClone(n, mp));
            }
            else{
                root->neighbors.push_back(mp[n]);
            }
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        return createClone(node, mp);
    }
};