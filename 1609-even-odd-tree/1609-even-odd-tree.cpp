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
    //For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
    //For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).//

    bool odd(vector<int>&arr) {

        if (arr.size() == 1 && arr[0]%2!=0) return false;

        for (int i=0; i<arr.size()-1; i++) {

            if (arr[i]%2 != 0 || arr[i] <= arr[i+1]) return false;

        }
                if (arr[arr.size()-1]%2 != 0) return false;

        return true;

    }
    bool even (vector<int>&arr) {

        if (arr.size() == 1 && arr[0]%2==0) return false;

        for (int i=0; i<arr.size()-1; i++) {

            if (arr[i]%2 == 0 || arr[i] >= arr[i+1]) return false;

        }

        if (arr[arr.size()-1]%2 == 0) return false;

        return true;
    }


    bool isEvenOddTree(TreeNode* root) {
        
        // if (root->val%2 == 0) return false;

        int level = 0;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> temp;
            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                temp.push_back(node->val);
            }

            if (level%2 == 0) {
                if (!even(temp)) return false;
            } else if (level%2 != 0) {
                if (!odd(temp)) return false;
            }
            level++;

        }

        return true;


    }
};