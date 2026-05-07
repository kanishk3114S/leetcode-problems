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
        TreeNode* solver(vector<int>&preorder , int upperbound , int&idx) {
        if (idx == preorder.size() || preorder[idx] > upperbound) return NULL;
            TreeNode* root = new TreeNode(preorder[idx++]);

            root->left = solver(preorder , root->val , idx);
            root->right = solver(preorder , upperbound , idx);

            return root;

        }

        TreeNode* bstFromPreorder(vector<int>& preorder) {
            
            int idx = 0;
            return solver(preorder , INT_MAX , idx);
        }
};