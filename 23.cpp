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
