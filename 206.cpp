// reverse the given linked list
// TC = O(N) SC=O(N)

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
    ListNode* reverseList(ListNode* head) {
       ListNode* temp = head;
       stack<int> tempst;
        while(temp!=NULL){
            tempst.push(temp->val);
            temp=temp->next;
        }

        temp=head;
        while(!tempst.empty()){
            temp->val=tempst.top();
            tempst.pop();
            temp = temp->next;
        }

        return head;
    }
};