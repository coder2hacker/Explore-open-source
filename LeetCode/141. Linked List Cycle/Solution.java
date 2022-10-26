class Solution {
    
    //  Time Complexity = O(N)
    //  Space Complexity = O(1)
    
    public boolean hasCycle(ListNode head) {
        //   Edge Case
        if(head == null )
            return false;
        
        //  2 Pointers slow and fast
        ListNode slow = head, fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;      //  2 times of slow pointer
            
            //  if slow pointer met the same value as of fast pointer then it means linked list contains cycle inside it
            if(slow == fast)
                return true;
        }
        
        return false;
    }
}
