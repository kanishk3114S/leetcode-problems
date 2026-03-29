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

    int solver(Node* root , int&maxcnt , int cnt) {

        if (root == NULL) return maxcnt;

        //for every node there will be children[i] calls//
        maxcnt = max(cnt , maxcnt);
        for (int i=0; i<root->children.size(); i++) {
            
            solver(root->children[i] , maxcnt , cnt + 1);
        }

        return maxcnt;

    }

    int maxDepth(Node* root) {
        int maxcnt = 0;
        return solver(root , maxcnt , 1);

    }
};