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
    void dfs(TreeNode* root1 , vector<int>&res) {

        if (root1==NULL) return;

        res.push_back(root1->val);
        dfs(root1->left,res);
        dfs(root1->right , res);

    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        vector<int> res;
        dfs(root1,res);
        dfs(root2,res);
        sort(res.begin(),res.end());
        return res;

    }
};