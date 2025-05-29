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
        auto compare=[](ListNode* a, ListNode*b){
            return a->val > b->val;
        };
        priority_queue<ListNode* , vector<ListNode*>, decltype(compare)> pq(compare);
        for(ListNode* list : lists){
            if(list){
                pq.push(list);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = curr;
            if(curr->next!=NULL){
                pq.push(curr->next);
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;

    }
};