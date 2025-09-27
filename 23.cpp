// this is the solution of complexity O(nlogn)


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

        priority_queue<int,vector<int>,greater<int>>minheap;

        for(auto list : lists){
            ListNode* temp = list;
            while(temp){
                minheap.push(temp->val);
                temp = temp->next;
            }
        }

        if(minheap.empty())return NULL;

        ListNode* ans = new ListNode(minheap.top());
        ListNode* temp2 = ans;
        minheap.pop();
        while(!minheap.empty()){
            ListNode* newnode = new ListNode(minheap.top());
            minheap.pop();
            temp2->next = newnode;
            temp2 = newnode;

        }

        return ans;
    }
};


// this is the solution with the complexity O(nlogk) (k being the no of lists )

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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val >b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> q;

        for(auto node:lists){
            if(node) q.push(node);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!q.empty()){
            ListNode* curr = q.top();
            q.pop();
            tail->next = curr;
            tail = tail->next;

            if(curr->next) q.push(curr->next);
        }

        return dummy.next;
        
    }
};
