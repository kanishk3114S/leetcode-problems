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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode* , long long>> q;

        q.push({root , 0}); //it will store the root and the index//
        int ans = 0;

        while(!q.empty()) {

            int size = q.size();
            int min = q.front().second;
            int first = 0 , last = 0;
            for (int i=0; i<size; i++) {
                
                TreeNode* node = q.front().first;
                long long idx = q.front().second-min;
                q.pop();
                if (i == 0) first = idx;
                if (i==size-1) last = idx; //store the first and last//

                if (node->left != NULL) q.push({node->left , 2*idx + 1});
                if (node->right != NULL) q.push({node->right , 2*idx + 2});

            }

            ans = max(ans , last-first+1);
        
        }

        return ans;

    }
};