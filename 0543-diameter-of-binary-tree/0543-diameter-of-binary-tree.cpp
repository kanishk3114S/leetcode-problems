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
  int geth(TreeNode* root) { //O(N) time complexity//

    if (root == NULL) return 0;

    int l = geth(root->left);
    int r = geth(root->right);

    return 1+max(l,r);

  }

void dfs(TreeNode*root , int& ans) {

    if (root == NULL) return;

    //at every node//

    int left = geth(root->left); //we get the left height//
    int right = geth(root->right); // we get the right height//

    int diameter = left+right;

    ans = max(diameter , ans);

    //traverse the tree//

    dfs(root->left ,ans);
    dfs(root->right , ans);

}

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        dfs(root , ans);
        return ans;
    }
};