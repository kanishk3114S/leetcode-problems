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
    int getHeight(TreeNode* root , int& maxh) { 

        if (root == NULL) return 0;

        int left = getHeight(root->left , maxh);
        int right = getHeight(root->right, maxh);
        maxh = max(maxh ,left+right);


        //at every node--> we have left and right which gives us lefth and righth//
        // but we used to calculate the 1+max(left,right) because for root that is the height//
        //and while getting the answer this happens with every node//

        //so lh+rh maintain karrrrrrrrrrrrrrrrrrrlo//

        return 1+max(left,right);


    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxh = 0;
        getHeight(root , maxh);
        return maxh;
    }
};