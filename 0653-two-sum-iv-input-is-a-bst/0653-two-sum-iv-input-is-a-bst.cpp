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
  //create a class of BST iterator where the object is the variable//

  class BSTiterator {

    private:
    stack<TreeNode*>s;
    bool reverse;
    TreeNode* temp;

    public:
    BSTiterator(TreeNode*root , bool isreverse) {

        reverse = isreverse;
        
        if(!reverse) {

            temp = root;
            while (temp!=NULL) {
                s.push(temp);
                temp = temp->left;
            }

        } else {

            temp = root;
            while (temp!=NULL) {
                s.push(temp);
                temp = temp->right;
            }

        }

    }

    int next() {

        int ans = s.top()->val;
        TreeNode* node = s.top();
        s.pop();
        if (!reverse) {
            if (node->right) {
                temp = node->right;
                while(temp!=NULL) {
                    s.push(temp);
                    temp = temp->left;
                }
            }
        } else {

            if (node->left) {
                temp=node->left;
                while(temp!=NULL){
                    s.push(temp);
                    temp=temp->right;
                }
            }

        }
        return ans;

    }

    bool hasnext() {
        return !s.empty();
    }

  };


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
       
        BSTiterator l(root , false);
        BSTiterator r(root , true);

        int i=l.next();
        int j=r.next();

        while (i < j) {

            if (i+j == k) {

                return true;

            } else if (i+j > k) {
                j = r.next();
            } else {
                i = l.next();
            }

        }

        return false;
        
    }
};