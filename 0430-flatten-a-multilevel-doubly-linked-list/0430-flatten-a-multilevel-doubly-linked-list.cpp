/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
    Node* curr = head;

    while (curr != NULL) {

        //find the child  pointer//
        
        if (curr->child != NULL) {
            Node* next = curr->next;
            curr->next = flatten(curr->child);
            curr->child->prev = curr;
            curr->child = NULL;


            while (curr->next != NULL) {
                curr = curr->next;
            }

            if (next != NULL) { //next is not null that means its not tail//
                curr->next = next;
                next->prev = curr;
            }
        }

        curr = curr->next;

    }

    return head;

    }
};