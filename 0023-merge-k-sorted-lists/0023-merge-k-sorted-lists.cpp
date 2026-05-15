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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //Heaps of linked list stores the linked list with the smallest pointer value//
        struct cmp {
            
            bool operator()(ListNode* a, ListNode* b) {
                
                if (a && b) return a->val > b->val;

                return false;
            }
        };
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq; //min heap//

        if(lists.size() == 0) return NULL;

        for (int i=0; i<lists.size(); i++) {

            if (lists[i]) {
            pq.push(lists[i]); //only heads are pushed//
            }

        }

        if (pq.size() == 0) return NULL;
        
        ListNode* node = pq.top();
        ListNode* head = NULL;
        if (node) {
        head = new ListNode(node->val);
        } else {
            return NULL;
        }
        pq.pop();
        if (node && node->next) {pq.push(node->next);}
        ListNode* temp = head;

        while (!pq.empty()) {

            ListNode* node = pq.top();
            ListNode* newnode = new ListNode(node->val);
            temp->next = newnode;
            pq.pop();
            if (node&&node->next) pq.push(node->next);
            temp = newnode;
        }

        return head;

    }
};