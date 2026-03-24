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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if (root == NULL) return result;
        else {
            q.push(root);
        }
        while (!q.empty()) {
        vector<int> level;

            int size = q.size();

            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop(); //now for a single node at a level//
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }

            result.push_back(level);

        }

        return result;

    }
};