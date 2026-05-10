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
class BSTIterator {
vector<int> res;
int ptr;
int len;
public:

    void inorder(TreeNode* root , vector<int>&res) {
        if (root==NULL) return;
        inorder(root->left , res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    BSTIterator(TreeNode* root) {
       inorder(root,res); 
        ptr = 0;
        len = res.size();
    }

    int next() {
        int ans = res[ptr];
        ptr++;
        return ans;
    }
    
    bool hasNext() {

    return ptr<len;
      
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */