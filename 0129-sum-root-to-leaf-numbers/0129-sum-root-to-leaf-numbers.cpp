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

    bool leaf(TreeNode* node) {
        return (node->left == NULL && node->right == NULL);
    }

    void dfs(TreeNode* root , string s , int&ans) {

        if (root == NULL) return;
        if (leaf(root)) {
            s += to_string(root->val);
            ans += stoi(s);
            return;
        }

        s+= to_string(root->val);

        dfs(root->left , s , ans);
        dfs(root->right , s , ans);

    }

    int sumNumbers(TreeNode* root) {

        int ans = 0;
        dfs(root,"",ans);
        return ans;
        
    }
};