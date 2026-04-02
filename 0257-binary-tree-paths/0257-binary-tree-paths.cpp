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
  bool dfs(TreeNode* root , TreeNode* b ,string& res) {

    if (root == NULL) return false;

    int len = res.size(); //save the length state//

    //calls//
    if (root == b) {
      res += to_string(root->val);
      return true;
    } else {
      res += to_string(root->val);
      res+= "->";
    }

   bool left =  dfs(root->left , b , res);
   bool right =  dfs(root->right , b , res);

    if (!left && !right) {
      res.resize(len);
      return false;
    }

    return true;
    
  }

  bool isleaf(TreeNode* root) {
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return true;
    return false;
  }

  void getleaf(TreeNode* root , vector<TreeNode*>&leaf) {
    if (root == NULL) return;
    if (isleaf(root)) leaf.push_back(root);
    getleaf(root->left , leaf);
    getleaf(root->right , leaf);
  }

  vector<string> binaryTreePaths(TreeNode* root) {

    vector<TreeNode*> leaf;
    getleaf(root , leaf);
    vector<string> ans;

    for (int i=0; i<leaf.size(); i++) {

    TreeNode* node = leaf[i];
    string res ="";
    dfs(root , leaf[i] , res);
    ans.push_back(res);

    }

    return ans;

  }
};