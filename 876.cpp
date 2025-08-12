// finding the middle of the linked list 
// TC=O(N) SC=O(1)


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
    ListNode* middleNode(ListNode* head) {
    //  first finding length of the linked list    
    int length = 0;
    if(head==NULL) return NULL;
    ListNode* temp = head ;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }

    int middle = (length/2)+1;
    temp = head;

    for(int i = 1;i<= middle ;i++){
        if(i==middle && temp!=NULL )return temp;
        temp=temp->next;
    }
    return temp;
    }
};

// Hare and tortoise approach 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
