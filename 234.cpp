// check if the linked list is palindrome 
// TC = O(2N) SC = O(1)

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
    ListNode*  reverse(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

    return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        // finding the middle of the ll by using hare and tortoise approach
        ListNode* slow = head ;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first = head;
        ListNode* second = reverse(slow->next);

        while(second!=NULL){
            if(first->val != second->val){
                reverse(slow->next);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverse(slow->next);
        return true;
    }
};