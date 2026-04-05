/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markparents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mpp)
{

    queue<TreeNode *> q;

    q.push(root);
    mpp[root] = NULL;

    while (!q.empty())
    {

        int size = q.size();

        for (int i = 0; i < size; i++)
        {

            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                q.push(node->left);
                mpp[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                mpp[node->right] = node;
            }
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    unordered_map<TreeNode *, TreeNode *> mpp;
    markparents(root, mpp);

    unordered_map<TreeNode *, bool> visited;
    visited[target] = true;
    queue<pair<TreeNode *, int>> q; // queue will contain the node and the distance//

    q.push({target, 0});

    while (!q.empty())
    {

        int size = q.size();
        int dist = 0;

        if (dist == k) break;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front().first;
            dist = q.front().second;

            q.pop();

            if (node->left != NULL && !visited[node->left])
            {
                q.push({node->left, dist + 1});
                visited[node->left] = true;
            }
            if (node->right != NULL && !visited[node->right])
            {
                q.push({node->right, dist + 1});
                visited[node->right] = true;
            }
            if (mpp[node] != NULL && !visited[mpp[node]])
            {
                q.push({mpp[node], dist + 1});
                visited[mpp[node]] = true;
            }
        }

        if (dist+1 == k) break;

    }

    vector<int> ans;

    while  (!q.empty()) {

        ans.push_back(q.front().first->val);
        q.pop();

    }

    return ans;

}
};