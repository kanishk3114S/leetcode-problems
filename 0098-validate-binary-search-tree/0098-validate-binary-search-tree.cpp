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

    void solver(TreeNode* root , long long& prev , long long& curr , bool& ans) {

        if (root == NULL) return;

        solver(root->left , prev , curr , ans);
        curr = root->val;
        if (prev != LLONG_MIN && curr <= prev) {
            ans = false;
            return;
        }
        prev = curr;
        solver(root->right , prev , curr , ans);

    }

    bool isValidBST(TreeNode* root) {

        bool ans = true;
        long long curr = LLONG_MIN , prev = LLONG_MIN;

        solver(root,prev, curr ,ans);

        return ans;
        
    }
};