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

    void inorder(TreeNode* root , vector<int>&v) {

        if (root==NULL) return;

        inorder(root->left , v);
        v.push_back(root->val);
        inorder(root->right , v);

    }
    TreeNode* solver(vector<int>&arr , int st , int end) {

        //base case//
        if (st > end) return NULL;

        int mid = (st+end)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = solver(arr , st , mid-1);
        root->right = solver(arr , mid+1 , end);

        return root;

    }

    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> v;
        inorder(root , v);
        return solver(v , 0 , v.size()-1);

    }
};