class Solution {
public:
    ListNode* re(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current) {
            ListNode *next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. Reverse both input lists
        ListNode* h = (l1);
        ListNode* h1 = (l2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        while (h || h1 || carry) {
            int val1 = (h) ? h->val : 0;
            int val2 = (h1) ? h1->val : 0;            
            int sum = val1 + val2 + carry;
            carry = sum / 10;            
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (h) h = h->next;
            if (h1) h1 = h1->next;
        }
        return (dummy->next);
    }
};