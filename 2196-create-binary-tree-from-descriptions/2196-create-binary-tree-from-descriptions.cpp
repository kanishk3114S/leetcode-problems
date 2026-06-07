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
    TreeNode* createBinaryTree(vector<vector<int>>& info) {
        
        unordered_map<int,TreeNode*> mpp;
        unordered_map<int,bool> hasparent;

        for (int i=0; i<info.size(); i++) {

            int p = info[i][0];
            int n = info[i][1];
            TreeNode* parent = NULL;
            TreeNode* child = NULL;
            if (mpp.count(p) && !mpp.count(n)) {

                parent = mpp[p];
                child = new TreeNode(n);

            } else if (!mpp.count(p) && mpp.count(n)) {

                parent = new TreeNode(p);
                child = mpp[n];

            } else if (!mpp.count(p) && !mpp.count(n)) {

                parent = new TreeNode(p);
                child = new TreeNode(n);
            } else {
                parent = mpp[p];
                child = mpp[n];
            }

            if (info[i][2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }

                mpp[p] = parent;
                mpp[n] = child;



            hasparent[n] = true;
            if (!hasparent.count(p)) {
                hasparent[p] = false;
            }

        }

        for (auto it:mpp) {

            if (!hasparent[it.first]) {
                return mpp[it.first];
            }

        }

        return NULL;

    }
};