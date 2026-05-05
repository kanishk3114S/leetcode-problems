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

    void solver (TreeNode* root ,unordered_map<int,int>&mpp) {

        if (root==NULL) return;

        mpp[root->val]++;
        solver(root->left , mpp);
        solver(root->right , mpp);

    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mpp;
        solver(root , mpp);
        vector<int> ans;
        int maxf = INT_MIN;
        for (auto it:mpp) maxf=max(maxf,it.second);

        for (auto it:mpp) if(it.second==maxf) ans.push_back(it.first);

        return ans;
    }
};