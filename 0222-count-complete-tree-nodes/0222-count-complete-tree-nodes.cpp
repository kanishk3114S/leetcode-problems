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
    void cntnodes(TreeNode* root , vector<int>& res) {
        if (root == NULL) return;

        res.push_back(root->val);
        cntnodes(root->left , res);
        cntnodes(root->right , res);
    }

    int countNodes(TreeNode* root) {
        
        vector<int> res;
        cntnodes(root , res);
        return res.size();

    }
};