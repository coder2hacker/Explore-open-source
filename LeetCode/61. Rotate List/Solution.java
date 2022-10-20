// https://leetcode.com/problems/rotate-list/

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        
        if(head == null)
            return head;
        
        int len= findLength(head);
        k = k % len ;
        
        if( k ==0 )
            return head;
        
        ListNode temp = head;
        
        for(int i=1; i<len-k; i++){
            temp = temp.next;
        }
        
        ListNode store = temp.next;
        temp.next = null;
        
        temp =  store;
        
        while(temp.next != null){
            temp = temp.next;
        }
        
        temp.next = head;
       return store;
    }
    
    int findLength(ListNode head){
        int len = 0;
        
        while(head!= null ){
            len ++;
            head = head.next;
        }
        
        return len;
    }
}
