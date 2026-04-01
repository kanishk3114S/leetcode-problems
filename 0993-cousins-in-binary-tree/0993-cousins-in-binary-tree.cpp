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
    bool sameparent(TreeNode* root , int x , int y) {

      if (root->left != NULL && root->right != NULL) {

          if ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)) return true;

      }

      return false;

    }

    bool isCousins(TreeNode* root, int x, int y) {
      
      if (root->val == x || root->val == y) return false;
      queue<TreeNode*> q;
      q.push(root);

      while (!q.empty()) {

        int size = q.size();
        bool foundx = false , foundy = false;        
        for (int i=0; i<size; i++) {

          TreeNode* node = q.front();
          q.pop();

          if (sameparent(node , x , y)) return false;

          if (node->left != NULL) {
            q.push(node->left);
            if (node->left->val == x) foundx = true;
            else if (node->left->val == y) foundy = true;
          }

          if (node->right != NULL) {
            q.push(node->right);
            if (node->right->val == x) foundx = true;
            else if (node->right->val == y) foundy = true;
          }

        }

        if (foundx && foundy) return true;
      }

      return false;


    }
};