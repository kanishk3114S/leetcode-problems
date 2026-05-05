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
    int count(vector<int>&arr) { //this function will give me the value//

        vector<pair<int,int>> v;

        for (int i=0; i<arr.size(); i++)v.push_back({arr[i] , i});

        sort(v.begin() , v.end());

        for (int i=0; i<arr.size(); i++){
            arr[i] = v[i].second;
        }

        int correctidx = 0;
        int i=0;
        int ans = 0;
        while (i<arr.size()) {

            correctidx = arr[i];

            if (arr[i] != arr[correctidx]) {
                swap(arr[i] , arr[correctidx]);
                ans++;
            } else {
                i++;
            }

        }
        return ans;

    }

    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;

        int ans = 0;

        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            vector<int> temp;
            for (int i=0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right)q.push(node->right);

                temp.push_back(node->val);


            }

            ans+=count(temp);

        }

        return ans;

    }
};