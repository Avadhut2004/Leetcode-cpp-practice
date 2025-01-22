// detecting cycle in a linked list 
// TC=O(N) SC =O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        if(head==NULL || head->next==NULL)return false;
        while(true){
            if(temp->next==NULL)return false;
            else if(temp->next->val== INT_MAX)return true;
            temp->val=INT_MAX;
            temp=temp->next;
        }
        return false;
    }
};