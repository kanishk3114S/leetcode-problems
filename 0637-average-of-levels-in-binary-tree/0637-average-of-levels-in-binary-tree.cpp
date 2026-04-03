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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);
        vector<double> ans;

        while (!q.empty()) {

            int size = q.size(); //take the level//
            double sum = 0 , avg = 0;
            for (int i=0; i<size; i++) { //iterate over it and push the next level on to queue//

            TreeNode* node = q.front();
            q.pop();
    
            sum += node->val;

            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push(node->right);

            }

            avg = sum/size;
            ans.push_back(avg);

        }

        return ans;

    }
};