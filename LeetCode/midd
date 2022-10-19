class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr)
        {
            return head;
        }  
    ListNode*slow=head,*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    }
};
