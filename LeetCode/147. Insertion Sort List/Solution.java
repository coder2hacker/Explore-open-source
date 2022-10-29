class Solution {
    public ListNode insertionSortList(ListNode head) {
        for(ListNode cur = head; cur != null; cur = cur.next) 
            for(ListNode j = head; j != cur; j = j.next) 
                if(j.val > cur.val)
                    j.val = j.val ^ cur.val ^ (cur.val = j.val);         // swap       
        return head;
    }
}
