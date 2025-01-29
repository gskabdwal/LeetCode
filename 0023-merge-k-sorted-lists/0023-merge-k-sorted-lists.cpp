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
    class Compare{
        public:
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        ListNode head(0);
        ListNode *curNode = &head;
        priority_queue<ListNode*,vector<ListNode*>,Compare>  pq; 
        for(int i =0; i<lists.size(); i++){
            if(lists[i]) pq.push(lists[i]);
        }

        while(pq.size()>0){
            curNode->next=pq.top();
            pq.pop(); 
            curNode = curNode->next;
            if(curNode->next) {
                pq.push(curNode->next); 
            }
        }
        return head.next;
}
};