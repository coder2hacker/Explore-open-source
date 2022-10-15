// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode sortedList = null;
        ListNode head = null;
        while(list1 != null && list2 != null){
            if(list1.val <= list2.val){
                if(sortedList == null){
                    sortedList = new ListNode(list1.val);
                    head = sortedList;
                }                    
                else{
                    sortedList.next = new ListNode(list1.val);
                    sortedList = sortedList.next;
                }
                list1 = list1.next;
            }
            else{
               if(sortedList == null){
                    sortedList = new ListNode(list2.val);
                    head = sortedList;
                }  
                else{
                    sortedList.next = new ListNode(list2.val);
                    sortedList = sortedList.next;
                }
                list2 = list2.next;
            }
        }
        
       if(list1 != null){
            if(sortedList != null) 
                sortedList.next = list1;
            else 
               sortedList = list1;     
       } 
       else if(list2 != null){
           if(sortedList != null) 
                sortedList.next = list2;
           else
               sortedList = list2;
       }
        
        if(head != null)
            return head;
        return sortedList;
    }
}
