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
    vector<int> rightSideView(TreeNode* root) {
    
      //same concept as the top-bottom view//
      
    queue<pair<TreeNode*,int>> q;
    map<int,TreeNode*> mpp;
    vector<int> ans;
    if (root == NULL) return ans;
    q.push({root , 0});

      while (!q.empty()) {

        int size = q.size();

        for (int i=0; i<size; i++) {

            TreeNode* node = q.front().first;
            int y = q.front().second;
            q.pop();

            if (node->left != NULL) q.push({node->left , y+1});
            if (node->right != NULL) q.push({node->right , y+1});

            mpp[y] = node;

        }

      }

      for (auto it:mpp) {
        ans.push_back(it.second->val);
      }

      return ans;


    }
};