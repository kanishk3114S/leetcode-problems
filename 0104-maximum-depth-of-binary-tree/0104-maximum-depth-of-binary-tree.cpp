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

    int helper(TreeNode* root , int cnt , int& maxcnt) {

        if (root == NULL) return maxcnt;
        maxcnt = max(maxcnt , cnt);
        helper(root->left , cnt+1 , maxcnt);
        helper(root->right , cnt+1 , maxcnt);

        return maxcnt;
    }

    int maxDepth(TreeNode* root) {
        int maxcnt = 0;
       return helper(root , 1 , maxcnt);
    }
};