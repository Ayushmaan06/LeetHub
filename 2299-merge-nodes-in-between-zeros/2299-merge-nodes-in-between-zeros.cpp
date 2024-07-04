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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        ListNode* curr = head->next; // Skip the initial zero node
        ListNode* prev = dummy;
        
        while (curr != nullptr) {
            int sum = 0;
            // Summing values until the next zero
            while (curr != nullptr && curr->val != 0) {
                sum += curr->val;
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
            
            // Creating a new node with the sum and linking it
            prev->next = new ListNode(sum);
            prev = prev->next;
            
            // Skip the zero nodes
            while (curr != nullptr && curr->val == 0) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
