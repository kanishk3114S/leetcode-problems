class Solution {
public: 

struct D {
    int sum;
    long long mn;
    long long mx;
};

int ans=0;

    D solver(TreeNode* root) {

        if (root == NULL) return {0 , LLONG_MAX , LLONG_MIN};

        auto left = solver(root->left);
        auto right = solver(root->right);

        if (root->val > left.mx && root->val < right.mn) {
            int currsum = root->val+left.sum+right.sum;
            ans = max(ans , currsum);
            return {root->val+left.sum+right.sum , min((long long)root->val , left.mn) , max((long long)root->val , right.mx)};

        }
        
        return {0, LLONG_MIN , LLONG_MAX};

    }


    int maxSumBST(TreeNode* root) {
        solver(root);
        return ans;
    }
};