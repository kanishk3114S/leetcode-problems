/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool dfs(ListNode* lnode , TreeNode* root) {

        if (lnode == NULL && root == NULL) return true;
        if (lnode == NULL && root != NULL) return true;
        if (lnode != NULL && root == NULL) return false;
        if (root->val != lnode->val) return false;

        bool left = dfs(lnode->next , root->left);
        bool right = dfs(lnode->next , root->right);

        if (left || right) return true;

        return false;

    }

    bool preorder( ListNode* head , TreeNode* root) {

        if (root==NULL) return false;
        if (dfs(head , root)) return true;
        bool left = preorder(head , root->left);
        bool right = preorder(head , root->right);

        if (left || right) return true;

        return false;
        
    }


    bool isSubPath(ListNode* head, TreeNode* root) {
        return preorder(head , root);
    }
};