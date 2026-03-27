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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;

        q.push(root);
        bool flag = true;

        while (!q.empty()) { //when queue get empty the traversal is over..//

            int size = q.size();
            vector<int> sample;
            for (int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                sample.push_back(node->val);

            }

            if (flag) ans.push_back(sample);
            else {
                reverse(sample.begin() , sample.end());
                ans.push_back(sample);
            }

            flag = !flag;

        }

        return ans;


    }
};