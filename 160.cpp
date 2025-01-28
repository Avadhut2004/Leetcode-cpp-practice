// intersection of two linked lists 
// approach by using hashing 

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 =  headA;
        ListNode* head2 = headB;

        unordered_set<ListNode*>st;
        while(head1!=NULL){
            st.insert(head1);
            head1 = head1->next;
        }

        while(head2!=NULL){
            if(st.find(head2)!=st.end()) return head2;
            head2=head2->next;
        }

        return NULL;
    }
};


// we can reduce the searching length by calculating positive length difference between the two lists 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 =  headA;
        ListNode* head2 = headB;

        // finding the length of both the lists 

        int l1 = 0;
        while(head1!=NULL){
            l1++;
            head1 = head1->next;
        }
        
        int l2 = 0 ;
        while(head2!=NULL){
            l2++;
            head2 = head2->next;
        }

        head1 = headA;
        head2 = headB;

        int diff = l1-l2;
        // if diff + -> l1>l2(move head1) else otherwise

        if(diff<0){
            while(diff++!=0)head2 = head2->next;
        }
        else if(diff>0) {
            while(diff--!=0) head1 = head1->next;
        }

        while(head2!=NULL){
            if(head2 == head1)return head1;
            head2 = head2->next;
            head1 = head1->next;
        }        

        return NULL;
    }
};

// the optimal solution can be derived from the same concept of difference of lengths 


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;

        while(d1!=d2){
            if(d1 == NULL){
                d1 = headB;
                d2 = d2->next;
            } 
            else if(d2 == NULL) {d2 = headA;
            d1 = d1->next;
            }
            else{
                d2 = d2->next;
                d1 = d1->next;
            }
            
        }

        return d1;
    }
};
