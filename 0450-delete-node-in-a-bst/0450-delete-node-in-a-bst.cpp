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
    TreeNode* goleft(TreeNode*root) {

        if (root->left == NULL) return root;

        return goleft(root->left);

    }

    
    TreeNode* goright(TreeNode*root) {

        if (root->right == NULL) return root;

        return goright(root->right);

    }
    TreeNode* solver(TreeNode* root, int key , TreeNode* prev) {

        //base case//
        if (root==NULL) return NULL;

        if (root->val == key) {
            //we have found our node//

            if (prev->val > key) {

                //we are in left//

                if (root->left) {
                    prev->left = root->left;
                    goright(root->left)->right = root->right;
                    
                }else {

                prev->left = root->right;

            }
        } else {
            //we are in the right//
            if (root->right) {
            prev->right = root->right;
            goleft(root->right)->left = root->left;

            }
            

            else {
                prev->right = root->left;
            }

        }

            } 

        //calls//

        if (root->val > key) {

            prev = root;
            return solver(root->left , key , prev);

        } else {

            prev = root;
            return solver(root->right , key , prev);

        }

    }


    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;

        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) return NULL;
            
                if (root->left) {
                    goright(root->left)->right = root->right;
                    return root->left;
                } else {
                    return root->right;
                }

            
        }

        solver(root , key , NULL);
        return root;
    }
};