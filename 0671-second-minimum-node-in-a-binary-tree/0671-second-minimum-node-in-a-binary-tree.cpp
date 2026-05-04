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

    void solver(TreeNode* root , set<int>&s) {

        if (root==NULL) return;

        solver(root->left , s);
        s.insert(root->val);
        if (s.size() > 2) s.erase(prev(s.end()));;
        solver(root->right , s);

    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        solver(root,s);
        if (s.size() == 1)return -1;

        return *s.rbegin();
    }
};