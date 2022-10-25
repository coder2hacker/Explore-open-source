/*
Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6 */
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         int k=lists.size();
        if(k==0)
            return NULL;
        vector<pair<int, ListNode*>> a;
        for(int i=0;i<k;i++)
        {
          ListNode* n=lists[i];
            while(n!=NULL)
            {
                a.push_back({n->val,n});
                n=n->next;
            }
        } 
        if(a.size()==0)
            return NULL;
        sort(a.begin(),a.end());
        
        for(int i=0;i<a.size()-1;i++)
        {
            a[i].second->next=a[i+1].second;
        }
        a[a.size()-1].second->next=NULL;
        return a[0].second;
    }
};
