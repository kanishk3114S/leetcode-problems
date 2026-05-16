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

using ll = long long;
const ll MOD = 1e9+7;

    ll solver(TreeNode* root , ll&maxprod , ll total) {

        if (root == NULL) return 0;

        ll left = solver(root->left,maxprod,total);
        ll right = solver(root->right,maxprod , total);

        ll currsum = root->val+left+right;
        ll rem = total-currsum;
        maxprod = max(maxprod, (currsum * 1LL * rem));
        // maxprod = maxprod%MOD;

        return currsum;

    }

    void sum(TreeNode* root , ll&Sum) {

        if (root==NULL) return;

        Sum+=root->val;
        sum(root->left,Sum);
        sum(root->right,Sum);

    }

    int maxProduct(TreeNode* root) {
        ll Sum = 0;
        sum(root , Sum);
        ll maxprod = LLONG_MIN;
        solver(root , maxprod , Sum);
        return maxprod%MOD;

    }
};