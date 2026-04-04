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
        return root->left == NULL && root->right == NULL;
    }

    bool solver(TreeNode* root , int sum , int target) {

        //base case//
        if (root == NULL) return false;

        //calls//
        sum += root->val;

        if(isleaf(root)) {

            if (sum == target) return true;
            else return false;

        } 

        bool left = solver(root->left , sum , target);
        bool right = solver(root->right , sum , target);

        if (left || right) return true;

        sum -= root->val;

        return false;

    }

    bool hasPathSum(TreeNode* root, int target) {
        return solver(root , 0 , target);
    }
};