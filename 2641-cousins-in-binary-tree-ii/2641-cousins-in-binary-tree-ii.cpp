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
  void markparents(TreeNode* root , unordered_map<TreeNode*,TreeNode*>&parents) {
        queue<TreeNode*> q;
        q.push(root);
        parents[root] = NULL;
        while (!q.empty()) {

            int size  = q.size();
            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {q.push(node->left); parents[node->left] = node;}
                if (node->right != NULL) {q.push(node->right); parents[node->right] = node;}
            }
        }


  }

    TreeNode* replaceValueInTree(TreeNode* root) {

        // every node must have the .. total sum - sum of its group//
        
        //lets map the {level , {node , sum}} //

        map<int,int> smallmap;
        unordered_map<TreeNode*,TreeNode*> parents;
        unordered_map<TreeNode* , int> mpp;
        markparents(root , parents);

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {

            int size  = q.size();
            int sum = 0;
            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                int childsum = 0;
                q.pop();

                if (node->left != NULL) {

                    q.push(node->left);
                    childsum+= node->left->val;
                }

                if (node->right != NULL) {

                    q.push(node->right);
                    childsum += node->right->val;

                }

                mpp[node] = childsum;

                sum += node->val;

            }

            smallmap[level] = sum;
            level++;
        }


    // for (auto it:smallmap) cout << it.first << " " << it.second << endl;

        q.push(root);
        level = 1;
        mpp[NULL] = root->val;
        while (!q.empty()) {

            int size = q.size();
            

            for (int i=0; i<size; i++) {


                TreeNode* node = q.front();
                q.pop();
                int levelsum = smallmap[level];
                int nodesum = mpp[parents[node]];

                // cout << nodesum << endl;

                node->val = levelsum-nodesum;
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

            }
            level++;
        }   

        return root;

    }
};