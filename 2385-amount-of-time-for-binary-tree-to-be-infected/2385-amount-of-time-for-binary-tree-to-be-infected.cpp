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
    void markparents(TreeNode* root , unordered_map<TreeNode* , TreeNode*>&mpp) {
        
        queue<TreeNode*> q;

        q.push(root);
        mpp[root] = NULL;

        while (!q.empty()) {

            int size = q.size();

            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) {
                    q.push(node->left);
                    mpp[node->left] = node;
                }
                if (node->right != NULL) {
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }
        }
    }

    TreeNode* findnode(TreeNode* root , int target) {

        if (root == NULL) return NULL;
        if (root->val == target) return root;

        TreeNode* L = findnode(root->left , target);
        TreeNode* R = findnode(root->right , target);

        if (L) return L;
        else if(R) return R;

        return NULL;

    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> mpp;
        unordered_map<TreeNode* , bool> vis;
        markparents(root , mpp);

        TreeNode* target = findnode(root , start);
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int ans = 0;

        while (!q.empty()) {

            int size = q.size();

            bool infected = false;

            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    infected = true;
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    infected = true;
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if (mpp[node] && !vis[mpp[node]]) {
                    infected = true;
                    q.push(mpp[node]);
                    vis[mpp[node]] = true;
                }

            }

            if (infected) ans++;

        }
        return ans;

    }
};