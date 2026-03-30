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
    int geth(TreeNode* root) {

        if (root == NULL) return 0;

        int l = geth(root->left);
        int r = geth(root->right);

        return 1+max(l,r);

    }

    bool isCompleteTree(TreeNode* root) {

        int depth = geth(root); //1 based indexing//
        
        queue<TreeNode*> q;
        q.push(root);
        int currdepth = 0;
        bool gotnull = false;

        while (!q.empty()) {

            int size = q.size();
            currdepth ++;
            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                
                if (node->left != NULL) {

                    if (gotnull) return false;
                    else {
                        q.push(node->left);
                    }

                } else gotnull = true;
                if (node->right != NULL) {

                    if (gotnull) return false;
                    else {
                        q.push(node->right);
                    }

                } else gotnull = true;

                // if ((node->left != NULL || node->right != NULL) && currdepth != depth) return false;
            }
        }
        return true;

    }
};