class Solution {
public:
    void reverse(ListNode** h) {
        ListNode* current = *h;
        ListNode* prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *h = prev;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* current = head;
        int length = 1;

        while (current->next) {
            length++;
            current = current->next;
        }

        current->next = head; // make it a circular list
        k = length - k % length;

        while (k--) current = current->next;

        head = current->next;
        current->next = NULL;

        return head;
    }
};