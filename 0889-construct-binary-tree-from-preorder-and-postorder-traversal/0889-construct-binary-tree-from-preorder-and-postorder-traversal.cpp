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
    //assume they are the full binary trees so every root has equal left and rights//

    TreeNode* solver(vector<int>& preorder , vector<int>& postorder , int PreStart , int PreEnd , int PostStart , int PostEnd , unordered_map<int,int>&mpp) {

        if (PreStart > PreEnd || PostStart > PostEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[PostEnd]);

        if (PreStart == PreEnd) return root;

        int leftchild = preorder[PreStart+1];
        int left_idx = mpp[leftchild];

        int len = left_idx - PostStart + 1;

        root->left = solver(preorder , postorder , PreStart + 1 , PreStart + len , PostStart , left_idx , mpp);

        root->right = solver(preorder , postorder , PreStart+len+1, PreEnd , left_idx + 1, PostEnd - 1 , mpp);


        return root;

    }



    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        unordered_map<int,int> mpp;
        for (int  i=0; i<postorder.size(); i++) mpp[postorder[i]] = i;

        return solver(preorder , postorder , 0 , preorder.size()-1 , 0 , postorder.size()-1 , mpp);

    }
};