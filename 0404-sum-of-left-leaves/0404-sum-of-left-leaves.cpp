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
    bool isleaf (TreeNode* root) {

        return (root->left==NULL && root->right == NULL);

    }

    int solver(TreeNode* root , int idx) {
        
        if (root == NULL) return 0;

        if (root!=NULL && isleaf(root) && idx == 1) {
            return root->val;
        }
        if (root!=NULL && isleaf(root) && idx == 0) {
            return 0;
        }

        int l = solver(root->left , 1);
        int r = solver(root->right , 0);

        return l+r;



    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solver(root,0);
    }
};