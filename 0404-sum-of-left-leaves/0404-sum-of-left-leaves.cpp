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
    bool isleaf (TreeNode* root) {

        return (root->left==NULL && root->right == NULL);

    }

    int sumOfLeftLeaves(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;

        q.push({root , -1});
        int sum = 0;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                TreeNode* node = q.front().first;
                int num = q.front().second;
                q.pop();

                if (node->left != NULL) q.push({node->left , 1});
                if (node->right != NULL) q.push({node->right , 0});

                if (num == 1 && isleaf(node)) sum+=node->val;

            }

        }

        return sum;


    }
};