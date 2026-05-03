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
TreeNode *solver(TreeNode *root, int val, TreeNode *prev)
{

    if (root == NULL)
    {

        TreeNode *node = new TreeNode(val);
        if (prev->val > val) //to check which side to attach see the previous value//
        {
            prev->left = node;
        }
        else
        {
            prev->right = node;
        }

        return node;
    }
    if (root->val > val)
    {

        prev = root;
        return solver(root->left, val, prev);
    }
    else
    {

        prev = root;
        return solver(root->right, val, prev);
    }

    return NULL;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL) return new TreeNode(val);
    solver(root,val,NULL);
    return root;

}
};