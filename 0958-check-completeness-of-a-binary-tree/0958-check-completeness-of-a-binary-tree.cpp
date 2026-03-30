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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        bool gotnull = false; //do not reset for each level..//

        //this will check the completeness//

        //earlier....at each level is you see node after getting null node return false.....BUT thats for the last level..levels above that should be filled...//
        // therefore.....after resetting at each level we will treat eveyrhitng as leaf node//

        //what if....leaf case -- true....but one more level exists//

        //either for currdepth != depth check completeness and for the last case check leaf case//
        // or better----> if you encounter null you must not encounter a node//

        //made a global got null variable//

        while (!q.empty()) {

            int size = q.size();
            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                
                if (node->left != NULL) {

                    if (gotnull) return false;
                    else {
                        q.push(node->left);
                    }

                } else gotnull = true;
                if (node->right != NULL) {

                    if (gotnull) return false;
                    else {
                        q.push(node->right);
                    }

                } else gotnull = true;

            }
        }
        return true;

    }
};