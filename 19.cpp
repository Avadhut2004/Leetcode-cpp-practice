// delete nth node of a linked list from back 
// TC = O(N) SC=O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL) return head;
            ListNode* fast = head;
            ListNode* slow = head;

            // traversing fast ptr till nth index
            for(int i=0;i<n;i++){
                fast = fast->next;
            }
            if(fast==NULL)return head->next; // this means deletion of head 

            while(fast->next!=NULL){
                slow = slow->next ;
                fast = fast->next;
            }

            ListNode* temp = slow->next;
            slow->next = temp->next;
            delete(temp);

            return head;
    }
};