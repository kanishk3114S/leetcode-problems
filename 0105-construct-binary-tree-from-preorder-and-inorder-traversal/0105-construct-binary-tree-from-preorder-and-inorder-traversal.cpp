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
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder , int PreStart , int PreEnd , int InStart , int InEnd , map<int,int>&mpp) {

        if (PreStart > PreEnd || InStart > InEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[PreStart]);

        int root_idx = mpp[root->val];
        int nums = root_idx - InStart;

        root->left = tree(preorder , inorder , PreStart+1 , PreStart+nums , InStart , root_idx-1 , mpp);
        root->right = tree(preorder , inorder , PreStart+nums+1 , PreEnd , root_idx+1 , InEnd , mpp);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int>mpp;
        for (int i=0; i<inorder.size(); i++) mpp[inorder[i]]=i;

        TreeNode* root = tree(preorder , inorder , 0 , preorder.size()-1 , 0 , inorder.size()-1 , mpp);

        return root;

    }
};