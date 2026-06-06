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
    TreeNode* recoverFromPreorder(string st) {
        
        vector<pair<int,long long>> vec; //represent depth,node->val//

        int depth = 0;
        string temp = "";
        int num = 0;
        for (int i=0; i<st.length(); i++) {

            if (st[i] != '-') {

                while (i < st.length() && st[i] != '-') {
                    temp += (st[i]);
                    i++;
                }

                // cout << temp << endl;
                num = stoi(temp);
                vec.push_back({depth , (int)num});
                depth = 0;
                temp = "";
                i--;

            } else {
                depth++;
            }
        }

        // for (int i=0; i<vec.size(); i++) {
        //     cout << "d : " << vec[i].first << " & val : " << vec[i].second << endl;
        // }

        stack<pair<int,TreeNode*>> s;
        TreeNode* root = new TreeNode(vec[0].second);
        s.push({0 , root});

        for (int i=1; i<vec.size(); i++) {

        while (!s.empty() && vec[i].first <= s.top().first) {
            s.pop();
        }

        if (vec[i].first > s.top().first) {
                TreeNode* node = new TreeNode(vec[i].second);
                if (s.top().second->left == NULL) s.top().second->left = node;
                else s.top().second->right = node;

                s.push({vec[i].first , node});
            }
        
        }

        return root;

    }
};