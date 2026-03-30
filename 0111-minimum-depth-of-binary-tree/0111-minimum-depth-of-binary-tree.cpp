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

    bool isleaf(TreeNode* root) {

        if (root->left == NULL && root->right == NULL) return true;

        return false;
        
    }

    void solver(TreeNode* root ,int cnt ,  int&mincnt) {

        if (root == NULL) return;

        if (isleaf(root)) {
            mincnt = min(cnt, mincnt);
        }

        solver(root->left , cnt + 1 , mincnt);
        solver(root->right , cnt + 1 , mincnt);

    }

    int minDepth(TreeNode* root) {
        
        int mincnt = INT_MAX;
        solver(root , 1 , mincnt);
        return mincnt==INT_MAX ? 0 : mincnt;

    }
};