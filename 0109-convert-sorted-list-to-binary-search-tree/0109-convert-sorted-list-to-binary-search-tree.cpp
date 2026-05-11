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
    TreeNode* solver(vector<int>&arr , int st , int end) {

        //base case//
        if (st > end) return NULL;

        int mid = (st+end)/2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = solver(arr , st , mid-1);
        root->right = solver(arr , mid+1 , end);

        return root;

    }

    
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        
        return solver(arr , 0 , arr.size()-1);

    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL) return NULL;
        vector<int> arr;
        ListNode* temp = head;
        while (temp) {
            arr.push_back(temp->val);
            temp=temp->next;
        }
    return sortedArrayToBST(arr);
    }
};