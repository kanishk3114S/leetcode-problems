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

    void solver(TreeNode* root , string s , vector<string>& ans) {
        if (root == NULL) return;
        if (root->left==NULL&&root->right==NULL) {

            s += char(root->val+'a');
            ans.push_back(s);
            return;

        }
        s += (char)(root->val+'a');

        solver(root->left , s , ans);
        solver(root->right , s , ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        
        vector<string>ans;
        solver(root,"",ans);
        for(auto &s:ans){
            reverse(s.begin() , s.end());
        }
        sort(ans.begin() , ans.end());
        return ans[0];

    }
};