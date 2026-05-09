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
  int h(TreeNode*root) {
    if (root==NULL) return 0;
    int left = h(root->left);
    int right = h(root->right);
    return 1+max(left,right);
  }

  void solver(unordered_set<TreeNode*>&s , TreeNode*root , int d , int depth) {

    if (root==NULL) return;
    if ((root->left == NULL && root->right==NULL) && d == depth) {
        s.insert(root);
    }

    solver(s , root->left , d+1 , depth);
    solver(s , root->right , d+1 , depth);

  }

  TreeNode* lca(unordered_set<TreeNode*>&s , TreeNode* root) {

    if (root==NULL) return NULL;

    if (s.count(root)) {
        return root;
    }

    TreeNode* left = lca(s,root->left);
    TreeNode* right = lca(s,root->right);

    if (left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
    
    return NULL;

  }

  TreeNode* lcaDeepestLeaves(TreeNode* root) {

    unordered_set<TreeNode*> s;
    int depth = h(root);
    solver(s , root, 1 , depth);
    return lca(s , root);


    }
};