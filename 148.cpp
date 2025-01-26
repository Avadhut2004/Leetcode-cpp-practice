// sorting a linked list 
// TC = O(NlogN) SC=O(n)(due to recursion stack)

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
private:
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head ;
        ListNode*  fast = head->next;
        while(fast!=NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* first, ListNode* second) {
        // Dummy node to simplify logic
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge both lists while elements remain in either
        while (first != NULL && second != NULL) {
            if (first->val <= second->val) {
                tail->next = first;
                first = first->next;
            } else {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }

        // Append any remaining elements from either list
        if (first != NULL) tail->next = first;
        if (second != NULL) tail->next = second;

        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        // base case 
        if(head==NULL || head->next == NULL ) return head;

        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head ;
        ListNode* righthead = middle->next ;
        middle->next=NULL;
        lefthead = sortList(lefthead);
        righthead =sortList(righthead);

        return merge(lefthead,righthead);
        
    }
};