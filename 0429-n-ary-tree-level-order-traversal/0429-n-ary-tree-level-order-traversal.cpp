/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
vector<vector<int>> levelOrder(Node* root) {

    vector<vector<int>> ans; //to store the result//
    queue<Node*> q;

    if(root==NULL) return ans;
    else {
        q.push(root);
    }

    while (!q.empty()) {

        vector<int> level; //store every nodes of a particular level//
        int size = q.size();

        for (int i=0; i<size; i++) {

            Node* node = q.front();
            q.pop();
        for (auto child : node->children) {

            if (child != NULL) q.push(child);

       }
            level.push_back(node->val);

        }
        ans.push_back(level);

    }
    return ans;
}
};