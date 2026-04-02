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
    void dfs(TreeNode* root , vector<int>& res){ 

        if (root==nullptr) {
            res.push_back(-1e5);
            return;
        };

        dfs(root->left , res);
        dfs(root->right , res);
        res.push_back(root->val);


    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        vector<int> res1  ,res2;

        dfs(p , res1);
        dfs(q , res2);

        if (res1.size() != res2.size()) return false;

        for (int i=0; i<res1.size(); i++) {
            if (res1[i] != res2[i]) return false;
        }
        return true;

    }
};