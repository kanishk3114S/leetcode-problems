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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        
        unordered_map<int, TreeNode*> mpp;
        unordered_map<TreeNode* , bool> hasparent;

        for (int i=0; i<des.size(); i++) {

            if (!mpp.count(des[i][0]) && !mpp.count(des[i][1])) {

                TreeNode* parent = new TreeNode(des[i][0]);
                TreeNode* child = new TreeNode(des[i][1]);

                if (des[i][2] == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }

                mpp[parent->val] = parent;
                mpp[child->val] = child;
                hasparent[child] = true;
            } else if (mpp.count(des[i][0]) && !mpp.count(des[i][1])) {

                TreeNode* parent = mpp[des[i][0]];
                TreeNode* child = new TreeNode(des[i][1]);
                if (des[i][2] == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }

                mpp[child->val] = child;
                hasparent[child] = true;
            } else if (!mpp.count(des[i][0]) && mpp.count(des[i][1])) {

                TreeNode* parent = new TreeNode(des[i][0]);
                TreeNode* child = mpp[des[i][1]];

                if (des[i][2] == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }                

                mpp[parent->val] = parent;
                hasparent[child] = true;    
            } else {
                TreeNode* parent = mpp[des[i][0]];
                TreeNode* child = mpp[des[i][1]];

                if (des[i][2] == 1) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }                

                mpp[parent->val] = parent;
                hasparent[child] = true;  


            }

        }

        TreeNode* root = NULL;

        for (auto it:mpp) {
            
            if (!hasparent.count(it.second)) {
                return it.second;
            }

        }

        return NULL;

    }
};