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
    TreeNode* solver(vector<int>& inorder, vector<int>& postorder , int InStart , int InEnd , int PostStart , int PostEnd , unordered_map<int,int>&mpp) {

        if (InStart > InEnd || PostStart > PostEnd) return NULL;
        //if either of the array is empty we return null..//

        TreeNode* root = new TreeNode(postorder[PostEnd]);

        int root_idx = mpp[root->val];
        int nums = root_idx - InStart;

        //now pass the calls for the left and the right//

        root->left = solver(inorder , postorder , InStart , root_idx-1 , PostStart , PostStart+nums-1 , mpp);
        root->right = solver(inorder , postorder , root_idx+1 , InEnd , PostStart+nums , PostEnd-1 , mpp);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> mpp;
    
    for (int i=0; i<inorder.size(); i++) mpp[inorder[i]] = i;

    TreeNode* root = solver(inorder , postorder , 0 , inorder.size()-1 , 0 , postorder.size()-1 , mpp);

    return root;

    }
};