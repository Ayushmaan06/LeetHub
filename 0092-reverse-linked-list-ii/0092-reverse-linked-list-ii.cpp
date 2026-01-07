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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        for (int i = 0; i < left - 1; i++) pre = pre->next;
        ListNode* curr = pre->next;
        ListNode* nxt = curr->next;
        for(int i = 0 ; i <abs(left-right) ; i++){
            curr->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
            nxt = curr->next;
        }
        return dummy.next;
    }
};