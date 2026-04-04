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
    bool isleaf(TreeNode* root) {
        return root->left ==NULL && root->right==NULL;
    }

    void solver(TreeNode* root , vector<int>& path , int sum , vector<vector<int>>& ans , int target) {

        //base case//

        if (root == NULL) return;

        path.push_back(root->val);
        sum += root->val;

        if (isleaf(root)) {

            if (sum == target) {
                ans.push_back(path);
                path.pop_back();
                return;
            } else {
                path.pop_back();
                return;
            }
        }

        solver(root->left , path , sum , ans , target);
        solver(root->right , path , sum , ans , target);

        path.pop_back();


    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        solver(root , path , 0 , ans , target);
        return ans;
    }
};