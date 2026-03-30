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
// we have to print the elements vertical line wise ... {-1,0,1,2,3} //
//at each vertical level we will have the multiple levels....every level having multielements//

//{vertical level , {level , {n1,n2,n3.....}}};

    vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    queue<pair<TreeNode*,pair<int,int>>> q;
    map<int,map<int,multiset<int>>> mpp;

    q.push({root , {0,0}}); //vertical level and horizontol level//

    while (!q.empty()) {

        int size = q.size();
        for (int i=0; i<size; i++) {
        TreeNode* node = q.front().first;
        int x = q.front().second.first , y = q.front().second.second;
            if (node->left != NULL) q.push({node->left , {x-1 , y+1}});
            if (node->right !=  NULL) q.push({node->right , {x+1 , y+1}});
        q.pop();
        mpp[x][y].insert(node->val);
        }
    }
    
    vector<vector<int>> ans;

    for (auto &x:mpp) {
        vector<int> sample;
        for (auto &y:x.second) {
            for (auto &val : y.second) {
                sample.push_back(val);
            }
        }
        // sort(sample.begin() , sample.end());
        ans.push_back(sample);
    }

    return ans;


    }
};