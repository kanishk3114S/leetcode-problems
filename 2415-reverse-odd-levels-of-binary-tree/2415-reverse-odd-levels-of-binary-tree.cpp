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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        bool odd = false;
        stack<int> s;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (!odd) {

                    if (node->left != NULL) {
                        s.push(node->left->val);
                        q.push(node->left);
                    }
                    if (node->right != NULL) {
                        s.push(node->right->val);
                        q.push(node->right);
                    }
                } else {

                    if (node->left != NULL) {
                        q.push(node->left);
                    }
                    if (node->right != NULL) {
                        q.push(node->right);
                    }   

                    node->val = s.top();
                    s.pop();

                }

            }

            odd = !odd;

        }

        return root;

    }
};