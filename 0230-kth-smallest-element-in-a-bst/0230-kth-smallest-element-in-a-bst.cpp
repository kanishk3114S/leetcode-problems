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
    void solver(TreeNode* root , int&cnt , int&ans , int k) {

        if (root==NULL)return;
        solver(root->left , cnt , ans , k);
        cnt++;
        if (cnt==k) {
            ans = root->val;
        }
        solver(root->right , cnt , ans , k);

    }


    int kthSmallest(TreeNode* root, int k) {
        
        int ans = 0 , cnt = 0;
        solver(root , cnt , ans , k);
        return ans;
    

    }
};