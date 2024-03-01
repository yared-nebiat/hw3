#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
Node* lltail(Node* head) {
    if(head == nullptr) {
        return nullptr;
    }
    if(head->next == nullptr) {
        return head;
    }
    return lltail(head->next);
}


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == nullptr) {
        // End of the original list
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    // Detach the current node from the list
    Node* current = head;
    head = head->next;
    current->next = nullptr;

    if (current->val > pivot) {
        larger = current;
        llpivot(head, smaller, larger->next, pivot);
    } else {
        smaller = current;
        llpivot(head, smaller->next, larger, pivot);
    }
}