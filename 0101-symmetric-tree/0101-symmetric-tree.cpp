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
    bool sametree(TreeNode*p , TreeNode*q) {

        //if i am going in right then simultenously in the next tree i should go in left//

        if (p==NULL || q==NULL) return p==q;

        bool left = sametree(p->left , q->right);
        bool right = sametree(p->right , q->left);

        if (!left || !right) return false;

        return p->val == q->val;

    }
    bool isSymmetric(TreeNode* root) {
        
        return sametree(root->left , root->right);

    }
};