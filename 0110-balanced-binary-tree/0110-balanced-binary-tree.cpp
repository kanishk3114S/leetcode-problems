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
    int height(TreeNode* root) { // a bottom up recursion where we calculate while returning//

        if (root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1+max(left,right);

    }

    bool isBalanced(TreeNode* root) {
      //brute force//  
        
        if(root == NULL) return true;

        int leftsum = height(root->left);
        int rightsum = height(root->right);

        if (abs(leftsum-rightsum) > 1) return false; //the moment we got the wrong//

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right) return false;

        return true;

    }
};