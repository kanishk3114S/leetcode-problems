/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //WE WILL find the answer using 3 methods//
        //if we found the root either of p || q return that//
        // if left || right is not null return that //
        // if left && right are not null return that//

        //since there is only one path lca will only have the left && right not null condition//
        //in that case we will pass the root//

        if (root == NULL || root == q || root == p) return root;

        TreeNode* left = lowestCommonAncestor(root->left , p , q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);

        if (left == NULL) return right; //even if right is NULL thats ok//
        else if (right == NULL) return left; //even if left is NULL thats ok//
        else return root; //both are not null//

        return root;

    }
};