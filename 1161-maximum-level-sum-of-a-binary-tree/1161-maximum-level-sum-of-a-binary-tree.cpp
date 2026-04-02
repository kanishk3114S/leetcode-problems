/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
struct comp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first)
            return a.first > b.first;   // greater first comes first
        return a.second < b.second;     // smaller second comes first
    }
}; 
int getMax(const set<pair<int,int> , comp>& s) {
    return s.begin()->second;
}

  
    int maxLevelSum(TreeNode* root) {


    queue<TreeNode*> q;
    set<pair<int,int> , comp> s;

    q.push(root);

    int maxi = INT_MIN;
    int level = 0;

    while (!q.empty()) {


        int size = q.size();
        int sum = 0;
        for (int i=0; i<size; i++) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left !=NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);

            sum += node->val;
        }

        level++;

        s.insert({sum , level});

    }

    return getMax(s);

    }
    };