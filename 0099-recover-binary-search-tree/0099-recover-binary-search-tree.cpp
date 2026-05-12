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

    private:
    TreeNode* first;
    TreeNode* second;
    TreeNode* third;
    TreeNode* curr;
    TreeNode* prev;

    void inorder(TreeNode* root) {

        if (root == NULL) return;

        inorder(root->left);

        //main function//

        curr = root;

        if (prev != NULL && (curr->val < prev->val) && first == NULL) {
            first = prev;
            second = curr;
        } else if (prev != NULL && (curr->val < prev->val) && first != NULL) {
            third = curr;
        }

        prev = curr;

        inorder(root->right);
    }


public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (third == NULL) {
            swap(first->val , second->val);
        } else if (third != NULL) {
            swap(first->val , third->val);
        }
    }
};