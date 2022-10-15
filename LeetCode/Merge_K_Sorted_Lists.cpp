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

class cmp{
    public:
    bool operator()(ListNode* a, ListNode*b){
        return a->val>b->val;
    };
};
    
class Solution {
    
    
    public:
    
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode*temp = res;
        
        priority_queue<ListNode*,vector<ListNode*>,cmp>q;
        int k = lists.size();
        for(int i = 0;i<k;i++) {
            if(lists[i]) q.push(lists[i]);
        }
        
        if(q.empty())  return NULL;
        
        while(!q.empty()){
            ListNode* n = q.top();
            q.pop();
            if(n->next) q.push(n->next);
            temp->next = n;
            n = n->next;
            temp = temp->next;
        }
        return res->next;
    }
};
