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
  int getsum(TreeNode* root , int& maxsum) {

    if (root == NULL) return 0;

    int leftsum = max(0 , getsum(root->left , maxsum)); //only consider the positive sum otherwise give 0.//
    int rightsum = max(0 , getsum(root->right , maxsum));
    maxsum = max(maxsum, root->val+leftsum+rightsum); //maxsum will be the current root + the left and the right sum;

    return root->val + max(leftsum , rightsum); //so basically from every node we are getting the maxpathsum..//

  }

int maxPathSum(TreeNode* root) {
    
    int maxsum = INT_MIN;
    getsum(root , maxsum);
    return maxsum;
    


}
};