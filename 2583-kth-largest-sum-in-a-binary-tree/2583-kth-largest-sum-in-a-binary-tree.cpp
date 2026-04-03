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
    long long kthLargestLevelSum(TreeNode* root, int k) {
     
    queue<TreeNode*> q;

    q.push(root);
    vector<long long> v;

    while (!q.empty()) {

        int size = q.size();
        long long sum = 0; //before moving to every level reset the sum to zero..//

        for (int i=0; i<size; i++) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL) q.push(node->left);
            if (node->right != NULL) q.push (node->right);
            
            sum += node->val;
        }
        v.push_back(sum);

    }

    sort(v.begin() , v.end() , greater<long long>());

    // for (int i=0; i<v.size(); i++) cout << v[i] << " ";

    return k > v.size() ? -1 : v[k-1];
    
}
};