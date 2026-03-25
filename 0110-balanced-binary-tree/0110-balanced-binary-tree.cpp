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
    int height(TreeNode* root , int maxcnt , int cnt) { // a bottom up recursion where we calculate while returning//

        if (root == NULL) return cnt; //when we reach the end we give the maximum depth reached//
        maxcnt = max(maxcnt , cnt);
        int left = height(root->left , maxcnt , cnt + 1);
        int right = height(root->right , maxcnt , cnt+ 1);
        return max(left , right);
    }

    bool isBalanced(TreeNode* root) {
      //brute force//  
        
        if(root == NULL) return true;

        int leftsum = height(root->left , 0 , 0);
        int rightsum = height(root->right , 0 , 0);

        if (abs(leftsum-rightsum) > 1) return false; //the moment we got the wrong//

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right) return false;

        return true;

    }
};