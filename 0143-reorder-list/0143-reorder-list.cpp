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

    ListNode* reverse(ListNode* curr , ListNode* prev) {

        if (curr == nullptr) return prev;

        ListNode* next = curr->next;
        curr->next = prev;
        return reverse(next , curr);

    }

    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

        }

        if (prev) {
            prev->next = nullptr;
        }

        //two heads----> head , slow//

        slow = reverse(slow , nullptr);

        ListNode* temp = head;
        ListNode* temp2 = slow;

        while (temp && temp2) {

            ListNode* next = temp->next;
            ListNode* next2 = temp2->next;
            temp->next = nullptr;
            temp2->next = nullptr;

            temp->next = temp2;
            temp2->next = next;

            temp = next;
            temp2 = next2;

        }

        temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        temp->next = temp2;

        

        // Node* newhead = nullptr;
        // bool chance  = true;

        // while (temp && temp2) {

        //     if (chance) {

        //         Node* next = temp->next;
        //         temp->next = nullptr;
        //         if (newhead==NULL) {
        //             newhead = temp;
        //         }

        //     }


        // }



    }
};