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
    int getH(TreeNode* root) {
        //Optimised solution to track the depth and check for the balance for every node//

        if (root == NULL) return 0;

        int L = getH(root->left);
        int R = getH(root->right);

        if (L==-1 || R==-1) return -1;
        if (abs(L-R) > 1) return -1;

        return 1+max(L,R);

    }

    bool isBalanced(TreeNode* root) {

        int result = getH(root);
        return result == -1 ? false : true;

    }
};